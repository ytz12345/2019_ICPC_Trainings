x = 998244353
y = int(input())
for i in range(1, 1000):
	for j in range(1, 1000):	
		if pow(i, x - 2, x) * j % x == y:
			print(j, i)
			exit(0)