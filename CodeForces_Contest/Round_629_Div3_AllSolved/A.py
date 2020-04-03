for i in range(int(input())):
    a, b = map(int, input().split())
    a %= b
    print(0 if a == 0 else b - a)