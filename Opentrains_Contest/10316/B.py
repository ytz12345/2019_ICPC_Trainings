f = open('input.txt', 'r')
w = open('output.txt', 'w')
n, t, c = 0, [], []
for i in range(int(f.readline())):
	s = f.readline()
	p = s.index('.')
	r = s[p + 1:]
	while r[-1] == '\n': r = r[:len(r) - 1]
	for j in range(n):
		if t[j] == r:
			c[j] += 1
			break
	else:
		t.append(r)
		c.append(1)
		n += 1
for i in range(n):
	w.write(t[i] + ': ' + str(c[i]) + '\n')