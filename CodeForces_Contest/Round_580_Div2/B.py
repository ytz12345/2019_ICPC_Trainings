n = int(input())
a = list(map(int, input().split()))
s, l, r, m = 0, 0, 0, 0
for i in a:
	if i <= -1:
		s += -1 - i
		l += 1
	elif i >= 1:
		s += i - 1
		r += 1
	else:
		m += 1
if m != 0 or l % 2 == 0:
	print(s + m)
else:
	print(s + 2)