import math

for i in range(int(input())):
	n, m = map(int, input().split())
	m *= 1000
	a = sorted([list(map(int, input().split())) for i in range(n)])[::-1]
	v, t = 0, 0
	for x, y in a:
		y /= 10 ** 6
		l = v * y + x * y * y / 2
		if l <= m:
			t += y
			m -= l
			v += x * y
		else:
			A, B, C = x / 2, v, -m
			dlt = B * B - 4 * A * C
			t += (-B + math.sqrt(dlt)) / (2 * A)
			m = 0
	if m > 0:
		t += m / v
	print('%.10f' %(t))