for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	c = []
	if len(set(a)) == 1:
		c = [1] * n
	else:
		c = [1 if i % 2 == 0 else 2 for i in range(n)]
		if c[0] == c[-1] and a[0] != a[-1]:
			for i in range(1, n):
				if a[i] == a[i - 1]:
					c[i] = c[i - 1]
					for j in range(i + 1, n):
						c[j] = 3 - c[j - 1]
					break
			else:
				c[-1] = 3
	print(len(set(c)))
	print(*c)