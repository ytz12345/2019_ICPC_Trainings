k = int(input())
s = input()
a = 0
while int(s, 2) > k:
	if s[1:].count('1'):
		p = 1 + s[1:].index('1')
		s = s[:p] + s[p + 1:]
	else:
		s = s[0] + s[2:]
	a += 1
print(a)