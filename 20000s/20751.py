t = int(input())
for _ in range(t):
    n, m, r, c, s = map(int, input().split())
    up = max(1, r-s)
    dn = min(n, r+s)
    le = max(1, c-s)
    ri = min(m, c+s)
    if up == 1 and le == 1 or dn == n and ri == m or up == 1 and dn == n or le == 1 and  ri == m:
        print('Tuzik')
    else: print('Barsik')