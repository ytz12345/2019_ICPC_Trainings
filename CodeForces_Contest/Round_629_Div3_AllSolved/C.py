num = '012'
for i in range(int(input())):
	n = int(input())
	x = [num.index(i) for i in input()]

	if n == 1:
		print(['0\n0', '1\n0', '1\n1'][x[0]])
		continue

	a, b, eq = [0] * n, [0] * n, 1
	if x[0] == 0:
		a[0], b[0], eq = 2, 1, 0
	elif x[0] == 1:
		a[0] = b[0] = 2
	else:
		a[0] = b[0] = 1
	for i in range(1, n):
		if x[i] == 0:
			a[i] = b[i] = 0
		elif x[i] == 1:
			if eq == 1:
				a[i], b[i], eq = 1, 0, 0
			else:
				a[i], b[i] = 0, 1
		else:
			if eq == 1:
				a[i] = b[i] = 1
			else:
				a[i], b[i] = 0, 2	
	print(''.join([num[i] for i in a]))
	print(''.join([num[i] for i in b]))		