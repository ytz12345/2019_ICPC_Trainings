#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

const double eps = 1e-10;

typedef vector<double> po;

typedef pair<po, int> pr;

int n, d;

po a[N];

vector <int> ans, res, base;

vector <pr> temp;

double sqr(double x) {return x * x;}

double abs(po x) {
	double res = 0;
	for (int i = 0; i < d; i ++)
		res += sqr(x[i]);
	return sqrt(res);
}

bool same(po x, po y) {
	for (int i = 0; i < d; i ++)
		if (fabs(x[i] - y[i]) > eps)
			return 0;
	return 1;
}
	
int main() {
	//#define ONLINE_JUDGE
	#ifndef ONLINE_JUDGE
		freopen("subset.in","r",stdin);
		freopen("subset.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for (int i = 0; i < n; i ++) {
		a[i].resize(d);
		for (int j = 0; j < d; j ++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i ++) {
		base.clear();
		temp.clear();
		int pivot = 0;
		for (int j = 0; j < d; j ++)
			if (a[i][j] != 0) {
				pivot = j;
				break;
			}
		for (int j = 0; j < n; j ++) {
			double rt = -a[j][pivot] / a[i][pivot];
			double len; po tmp; tmp.resize(d);
			for (int k = 0; k < d; k ++)
				tmp[k] = a[j][k] + a[i][k] * rt;

			if ((len = abs(tmp)) < eps) {
				base.push_back(j);
				continue;
			}
			int pos = -1;
			for (int k = 0; k < d; k ++)
				if (fabs(tmp[k]) > eps) {
					if (tmp[k] < 0) pos = k;
					break;
				}
			if (pos != -1) len = -len;
			for (int k = 0; k < d; k ++)
				tmp[k] /= len;
			temp.push_back(pr(tmp, j));
		}
		
		sort (temp.begin(), temp.end(), [&](pr a, pr b){
			for (int i = 0; i < d; i ++)
				if (a.first[i] != b.first[i])
					return a.first[i] < b.first[i];
			return a.second < b.second;
		});
		res.clear(); 
		for (int k = 0, j = 1; k < temp.size(); k = j ++) {
			while (j < temp.size() && same(temp[j].first, temp[j - 1].first)) j ++;
			if (j - k > res.size()) {
				res.clear();
				while (k < j) res.push_back(temp[k ++].second);
			}	
		}
		for (int k : base) res.push_back(k);
		if (res.size() > ans.size()) ans = res;
	}
	cout << (ans.size()) << endl;
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
	return 0;
}