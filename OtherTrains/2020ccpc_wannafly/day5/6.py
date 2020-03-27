x = 1
n = int(input())
for i in range(2, n + 1):x *= i
Mod = 10 ** 9 + 7
y = x * n * (n - 1) // 4 % Mod
print(y, y * y % Mod)