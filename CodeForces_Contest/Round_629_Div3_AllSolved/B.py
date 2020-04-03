for i in range(int(input())):
	n, k = map(int, input().split())
	k = n * (n - 1) // 2 - k + 1
	s = ['a'] * n
	p1 = p2 = 0
	c, sum = n - 1, 0
	while True:
		sum += c
		c -= 1
		if sum >= k:
			sum -= c + 1
			p2 = p1 + k - sum
			break
		p1 += 1
	#print(p1, p2)
	s[p1] = s[p2] = 'b'
	print(''.join(s))