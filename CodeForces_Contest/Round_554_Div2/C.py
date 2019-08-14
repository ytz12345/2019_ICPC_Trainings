from math import gcd
a, b = map(int, input().split())
c = abs(a - b)
x = a * b // gcd(a, b)
d = c - a % c
a += d
b += d
if a * b // c < x:
	print(d)
else:
	print(0)