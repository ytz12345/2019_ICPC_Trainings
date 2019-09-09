for i in range(int(input())):
	n, m, k = map(int, input().split())
	h = list(map(int, input().split()))
	for i in range(n - 1):
		if h[i] + m + k < h[i + 1]:
			print('NO')
			break
		else:
			m = m + h[i] - max(h[i + 1] - k, 0)
	else:
		print('YES')