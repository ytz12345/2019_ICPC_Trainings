for i in range(10):
	print(1000)
	s = ''
	for j in range(i + 10000, i + 11000):
		s += str(j) + ' '
	print(s)