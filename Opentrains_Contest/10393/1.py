for i in range(int(input())):
	s = input()                 
	n = (len(s) + 3) // 4
	t = hex(int(s, 2))[2:]
	t = '0' * (n - len(t)) + t
	w = ''
	for a in t:
		if a in 'abcdef':
			w += ['A', 'B', 'C', 'D', 'E', 'F']4['abcdef'.index(a)]
		else:
			w += a
	print(w)