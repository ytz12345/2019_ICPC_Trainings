input()
s = set(map(int, input().split()))
def no():
	print(-1)
	exit(0)
n = len(s)
if n > 3:
	no()
elif n == 1:
	print(0)
else:
	a = sorted([x for x in s])
	if n == 2: 
		m = a[1] - a[0]
		if m % 2 == 0:
			print(m // 2)
		else:
			print(m)
	elif a[0] + a[2] != a[1] + a[1]:
		no()
	else:
		print(a[1] - a[0])