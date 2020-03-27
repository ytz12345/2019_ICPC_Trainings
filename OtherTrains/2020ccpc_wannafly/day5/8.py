from math import sqrt

'''
s3 = sqrt(3)
dis = 2
n, m, k = 0, 0, 0
for i in range(1, 10 ** 6 + 1):
    x = i * s3
    y = int(x)
    if x * x + y * y > 1e6:break
    d = min(x - y, y + 1 - x)
    if d < dis:
        n, m, k = i, x, y
        dis = d
print(n, m, k, dis)
'''

x, y = 564719, 978122
a = [1, 1000000, 0]
b = [0, -x, y]
c = [0, -x, -y]

print(*a)
print(*b)
print(*c)