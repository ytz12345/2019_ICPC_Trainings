import math 

n = 100
f = [0 for i in range(n)]
f[1] = 1
for i in range(2, n):
	f[i] = f[i - 1] * 3 + f[i - 2] * 2
g = [0 for i in range(n)]

p = 998244353

g17 = 473844410
l = (3 + g17) * pow(2, p - 2, p)
r = (3 - g17) * pow(2, p - 2, p)
L = R = pow(g17, p - 2, p)
#(g17 * 5 - 17) / 17, (12 - g17 * 5) / 5

def calc(i):
	return (pow(l, i, p) * L - pow(r, i, p) * R) % p

print(calc(int(input())))