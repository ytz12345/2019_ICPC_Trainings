n = int(input())
s = sum([input() == 'LIE' for i in range(n)])
print(['TRUTH', 'LIE'][s & 1])