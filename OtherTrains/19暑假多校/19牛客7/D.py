n, p = input().split()
n = int(n)
if n < len(p):
	print('T_T')
else:
	print(p + '0' * (n - len(p)))