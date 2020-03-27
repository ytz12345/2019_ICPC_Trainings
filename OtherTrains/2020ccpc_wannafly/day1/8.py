def is_prime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return 0
        i += 1
    return 1

for i in range(int(input())):
    n, k = map(int, input().split())
    x = 1
    while x * k <= n:
        x += 1
    ans = k
    for i in range(2, x):
        if is_prime(i):
            ans *= i
    print(ans)