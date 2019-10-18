def f(s):
	a, b = s.count('0'), s.count('1')
	return ('0' if a < b else '1') * len(s)
s = input()
print(f(s) if s.count('0') != s.count('1') else (('0' if s[0] == '1' else '1') + f(s[1:])))