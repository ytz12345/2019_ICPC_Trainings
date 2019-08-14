n = int(input())
a = []
while n != 0:
	l = len(bin(n))
	a.append(l - 3)
	n ^= 1 << (l - 3)
	n += 1
print(len(a) * 2)
print(*a)