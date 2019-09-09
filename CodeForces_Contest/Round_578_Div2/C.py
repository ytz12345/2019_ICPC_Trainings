from math import gcd
n, m, q = map(int, input().split())
d = gcd(n, m)
x, y = n // d, m // d
for i in range(q):
	a, b, c, d = map(int, input().split())
	b = (b - 1) // [x, y][a == 2]
	d = (d - 1) // [x, y][c == 2]
	print('YNEOS'[b!=d::2])