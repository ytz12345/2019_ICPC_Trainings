a = list(map(int, input().split()))
print(*(sorted([max(a) - x for x in a])[1:]))