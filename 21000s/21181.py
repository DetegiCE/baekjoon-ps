n = int(input())
a = [int(input()) for _ in range(n)]
mn = 1e18
for i in a:
    for j in a:
        if i == j: continue
        s = 0
        for k in a:
            s += min(abs(i-k), abs(j-k)) ** 2
        mn = min(mn, s)            
print(mn)