n, l, r = map(int, input().split())
t = (r - l + 1) // 2
if r - l + 1 == n:
	print('[]' * (n // 2))
elif l == 1:
	print('[]' * t + '()' * (n // 2 - t))
elif r == n:
	print('()' * (n // 2 - t) + '[]' * t)
else:
	L, R = l - 1, n - r
	if L < R:
		print('(' * L + '[]' * t + ')' * L + '()' * ((R - L) // 2))
	else:
		print('()' * ((L - R) // 2) + '(' * R + '[]' * t + ')' * R)