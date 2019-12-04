for i in range(int(input())):
    n = int(input())
    l, r = 10 ** 10, -1
    for s, t in [list(map(int, input().split())) for i in range(n)]:
        l, r = min(l, t), max(r, s)
    print(max(r - l, 0))