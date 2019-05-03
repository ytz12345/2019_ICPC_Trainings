n = int(input())
s = bin(n)[2:]
s = '0' * (32 - len(s)) + s
'''
print(s)
print(s[16:])
print(s[:16][::-1])
'''
x = int(s[16:], 2)
y = int(s[:16][::-1], 2)
print(min(x + y + 1, n))