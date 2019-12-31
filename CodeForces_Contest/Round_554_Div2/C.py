from math import gcd
a, b = map(int, input().split())
c = abs(a - b)
a1, a2 = 0, a * b // gcd(a, b)
def work(x):
	global a, a1, a2
	y = x - a % x
	if y == x: 
		return
	if (a + y) * (b + y) // gcd(a + y, b + y) < a2:
		a1, a2 = y, (a + y) * (b + y) // gcd(a + y, b + y)
i = 1
while i * i <= c:
	if c % i == 0:
		work(i)
		work(c // i)
	i += 1
print(a1)