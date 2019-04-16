n, t = map(int, input().split())
p, k = -1, 10 ** 18
for i in range(n):
	a, b = map(int, input().split())
	if a < t:
		a += (t - a + b - 1) // b * b
	if a < k:
		k = a
		p = i
print(p + 1)