for i in range(int(input())):
    n = int(input())
    s = [input() for i in range(n)]
    t = set(s)
    print(n - len(t))

    p = {}
    for i in s:
        p[i] = 0
    for i in s:
        p[i] += 1
    
    for i in range(n):        
        if p[s[i]] == 1:
            print(s[i])
        else:
            p[s[i]] -= 1
            for j in range(10):
                r = str(j) + s[i][1:]
                if r not in p or p[r] == 0:
                    s[i] = r
                    p[s[i]] = 1
                    break
            print(s[i])