q, n = map(int, input().split())
q = q ** n - 1
i = 2
s = ''
while q > 1:
	if q % i == 0:
		s += str(i) + ' '
		while q % i == 0:
			q /= i
	i += 1
print(s)