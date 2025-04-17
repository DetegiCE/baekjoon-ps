n, t = map(int, input().split())
r = [int(input()) for _ in range(n)]
for _ in range(t):
    pos = -1
    mx = max(r)
    for i in range(n):
        if r[i] == mx:
            print(i+1)
            pos = i
            r[i] = 0
            break
    
    p = -1
    while mx > 0:
        mx -= 1
        p += 1
        t = p % n
        if pos == t:
            mx += 1
            continue
        r[t] += 1
