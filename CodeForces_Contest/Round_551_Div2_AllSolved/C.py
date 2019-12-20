n = int(input())
s = list(input())
a, b = s.count('('), 0
for i in range(n):
	if s[i] == '?':
		if a < n // 2:
			s[i] = '('
			a += 1
		else:
			s[i] = ')'
	if s[i] == '(':
		b += 1
	else:
		b -= 1
	if b < 0 or (b == 0 if i + 1 != n else b != 0):
		print(':(')
		exit(0)
print(''.join(s))