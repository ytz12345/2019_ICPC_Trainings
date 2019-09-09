
n=3000
print(n,n)

for i in range(n):
	s = ''
	for j in range(n):
		if (i+j&1):
			s+='1'
		else:
			s+='0'
	print(s)