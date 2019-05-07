#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MY_SUPER_PUPER_ONLINE_JUDGE
#include <iostream>
using namespace std;
#else
#include <fstream>
using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <type_traits>

template<class T>
struct Point
{
	T x, y;
	Point() {}
	Point(T x0, T y0)
	{
		x = x0;
		y = y0;
	}
};

template<class T1, class T2>
auto operator &(const Point<T1> &a, const Point<T2> &b) -> decltype(a.x + b.x)
{
	return a.x * b.y - a.y * b.x;
}

template<class T1, class T2>
auto operator *(const Point<T1> &a, const Point<T2> &b) -> decltype(a.x + b.x)
{
	return a.x * b.x + a.y * b.y;
}

template<class T1, class T2>
auto operator -(const Point<T1> &a, const Point<T2> &b) -> Point<decltype(T1() + T2())>
{
	return Point<decltype(T1() + T2())>(a.x - b.x, a.y - b.y);
}

bool compareAngle(const Point<int> &p1, const Point<int> &p2)
{
	if(p1.y == 0)
	{
		if(p2.y == 0) return p1.x < p2.x;
		return p1.x < 0 || p2.y > 0;
	}
	if(p1.y > 0 && p2.y <= 0) return false;
	if(p2.y > 0 && p1.y <= 0) return true;
	return p1.x * p2.y > p1.y * p2.x;
}

int n;

double calcSquare(const std::vector<Point<int>> &v, double angle, double &ma1, double &ma2, double &mb1, double &mb2)
{
	Point<double> a(cos(angle), sin(angle));
	ma1 = ma2 = v[0] * a;
	mb1 = mb2 = v[0] & a;
	for(int i = 1; i < n; ++i)
	{
		ma1 = min(ma1, v[i] * a);
		ma2 = max(ma2, v[i] * a);
		mb1 = min(mb1, v[i] & a);
		mb2 = max(mb2, v[i] & a);
	}
	return (ma2 - ma1) * (mb2 - mb1);
}

double calcSquare(const std::vector<Point<int>> &v, double angle)
{
	double ma1, ma2, mb1, mb2;
	return calcSquare(v, angle, ma1, ma2, mb1, mb2);
}

void makeConvex(std::vector<Point<int>> &v)
{
	sort(v.begin(), v.end(), compareAngle);
	int my = -1;
	for(int i = 0; i < n; ++i)
	{
		if(my == -1 || v[my].y > v[i].y) my = i;
	}
	int current = (my + 1) % n;
	std::vector<Point<int>> nv(1, v[my]);;
	nv.reserve(v.size());
	do
	{
		nv.push_back(v[current]);
		while(nv.size() > 2 && ((nv[nv.size() - 1] - nv[nv.size() - 2]) & (nv[nv.size() - 3] - nv[nv.size() - 2])) <= 0)
		{
			nv[nv.size() - 2] = nv.back();
			nv.pop_back();
		}
		if(current == my) break;
		current = (current + 1) % n;
	} while(1);
	nv.pop_back();
	nv.swap(v);
	n = static_cast<int>(v.size());
}

void printPoint(double a1, double b1, double c1, double a2, double b2, double c2, int ox, int oy)
{
	cout << c1 * b2 - c2 * b1 + ox << " " << a1 * c2 - a2 * c1 + oy << std::endl;
}

int main()
{
	cin >> n;
	std::vector<Point<int> > v(n);
	int ox = 0, oy = 0;
	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		ox += x;
		oy += y;
		v[i] = Point<int>(x, y);
	}
	ox /= n;
	oy /= n;
	for(int i = 0; i < n; ++i)
	{
		v[i].x -= ox;
		v[i].y -= oy;
	}
	makeConvex(v);
	cout << n << endl;
	for (int i = 0; i < n; i ++)
		cout << v[i].x << ' ' << v[i].y << endl;
	vector<double> angles;
	angles.reserve(v.size() * 2 + 2);
	const double pi = acos(-1.0);
	for(int i = 0; i < n; ++i)
	{
		int i1 = (i + 1) % n;
		double a = fmod(atan2(v[i].y - v[i1].y, (v[i].x - v[i1].x)) + 2 * pi, pi / 2);
		angles.push_back(a);
		angles.push_back(pi / 2 - a);
	}
	angles.push_back(0);
	angles.push_back(pi / 2);
	sort(angles.begin(), angles.end());
	double res = std::numeric_limits<double>::max(), res_an;
	for(int i = 1; i < static_cast<int>(angles.size()); ++i)
	{
		double s, a;
		s = calcSquare(v, angles[i]);
		a = angles[i];
		if(res > s)
		{
			res = s;
			res_an = a;
		}
	}
	cout << std::setprecision(6) << fixed;

	cout << res << endl;
	double ma1, ma2, mb1, mb2;
	calcSquare(v, res_an, ma1, ma2, mb1, mb2);
	printPoint(cos(res_an), sin(res_an), -ma1, sin(res_an), -cos(res_an), -mb1, ox, oy);
	printPoint(cos(res_an), sin(res_an), -ma1, sin(res_an), -cos(res_an), -mb2, ox, oy);
	printPoint(cos(res_an), sin(res_an), -ma2, sin(res_an), -cos(res_an), -mb2, ox, oy);
	printPoint(cos(res_an), sin(res_an), -ma2, sin(res_an), -cos(res_an), -mb1, ox, oy);
}
