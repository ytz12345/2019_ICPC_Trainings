
def sqr(x):return x*x
while True:
	x, y, r = map(int, input().split())

	p = [[2, 0], [-1, 2]]
	c = 0
	for i in p:
		if sqr(i[0] - x) + sqr(i[1] - y) <= r:
			c += 1
	print(c)