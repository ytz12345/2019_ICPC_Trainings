from fractions import Fraction

def sqr(x):
	return x * x

n = int(input())
a = [list(map(int, input().split())) for i in range(4)]

A = [0, 0] 
B = [0, 0] 
C = [0, 0] 
d = [0 for i in range(6)]

for i in range(n):
	A[0] = A[0] + (a[0][i] - a[1][i]) * (a[0][i] - a[1][i])
	B[0] = B[0] + (a[3][i] - a[2][i]) * (a[0][i] - a[1][i])
	C[0] = C[0] + (a[1][i] - a[3][i]) * (a[0][i] - a[1][i])

	B[1] = B[1] + (a[3][i] - a[2][i]) * (a[3][i] - a[2][i])
	C[1] = C[1] + (a[1][i] - a[3][i]) * (a[3][i] - a[2][i])

	d[2] = d[2] + (a[1][i] - a[3][i]) * (a[1][i] - a[3][i])

d[0], d[1], d[3], d[4], d[5] = A[0], B[1], C[0], C[1], B[0]

A[1] = B[0]

A = [Fraction(A[0], 1), Fraction(A[1], 1)]
B = [Fraction(B[0], 1), Fraction(B[1], 1)]
C = [Fraction(C[0], 1), Fraction(C[1], 1)]

x, y, one, ans = Fraction(0, 1), Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)

if A[0] == 0:
	A, B, C = A[::-1], B[::-1], C[::-1]
if A[1] != 0:
	B[1] = B[1] - (A[1] / A[0] * B[0])
	C[1] = C[1] - (A[1] / A[0] * C[0])

if B[1] != 0:
	y = -C[1] / B[1]
else:
	y = 0

C[0] = C[0] + B[0] * y

if A[0] != 0:
	x = -C[0] / A[0]
else:
	x = 0 

d = [Fraction(i, 1) for i in d]
ans = sqr(x) * d[0] + sqr(y) * d[1] + d[2] + d[3] * x * 2 + d[4] * y * 2 + d[5] * x * y * 2

t = str(ans.numerator) + '/' + str(ans.denominator)
print(t)