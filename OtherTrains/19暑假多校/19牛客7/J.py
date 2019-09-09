def f(s):
	return s[::-1]
for i in range(int(input())):
	a, b = input().split()
	a = int(f(a))
	b = int(f(b))
	x = int(f(str(a + b)))
	print(x)