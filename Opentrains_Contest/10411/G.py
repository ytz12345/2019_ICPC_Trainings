from fractions import Fraction

n = int(input())
n += 1
p = [list(map(int, input().split())) for i in range(n)]
vk = [Fraction(0, 1) for i in range(n)]
vv = [Fraction(0, 1) for i in range(n)]
for i in range(1, n):
	vk[i - 1] = Fraction(p[i][1] - p[i - 1][1], p[i][0] - p[i - 1][0])

def judge(k, b, x, y):
	return y - (k * x + b) == 0

def check():
	sumk = sumb = 0
	for i in range(1, n - 1):
		sumb += vv[i - 1] * p[i][0]
	for i in range(1, n - 1):
		sumk += -vv[i - 1]
	for i in range(n):
		if not judge(sumk, sumb, p[i][0], p[i][1]):
			return False
		if i > 0 and i < n - 1:
			sumb -= vv[i - 1] * p[i][0] * 2
			sumk += 2 * vv[i - 1]
	return True

s = Fraction(0, 1)
for i in range(1, n - 1):
	vv[i - 1] = (vk[i] - vk[i - 1]) * Fraction(1, 2)
	s += vv[i - 1]

if (s + vk[0]) == 0 and check():
	print('Yes')
else:
	print('No')