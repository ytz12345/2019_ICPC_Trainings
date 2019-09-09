import sys
for s in sys.stdin:
	x, a, y, b = map(int, s.split())
	if b * x < a * y:
		print('<')
	elif b * x == a * y:
		print('=')
	else:
		print('>')