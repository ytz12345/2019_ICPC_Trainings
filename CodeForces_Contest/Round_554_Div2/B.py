n = int(input())
ans = []
cnt = 0
def f(x):
	return x & (x + 1) == 0

while not f(n):
	s = bin(n)[2:]
	p = s.index('0')
	x = len(s) - p
	ans.append(x)
	n ^= (1 << x) - 1
	cnt += 1
	if f(n):
		break
	n += 1
	cnt += 1

print(cnt)
print(*ans)