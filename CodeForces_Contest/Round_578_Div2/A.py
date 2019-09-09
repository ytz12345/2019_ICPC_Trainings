n = int(input())
s = input()
a = ['0' for i in range(10)]
for i in range(n):
	if s[i] == 'L':
		a[a.index('0')] = '1'
	elif s[i] == 'R':
		a[9 - a[::-1].index('0')] = '1'
	else:
		a[int(s[i])] = '0'
print(''.join(a))