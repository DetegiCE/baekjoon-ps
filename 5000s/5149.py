for _ in range(int(input())):
    print(f'Data Set {_+1}:')
    n, m = map(int,input().split())
    s = []
    for i in range(n):
        x, y = map(int,input().split())
        s.append((x, y))
    t = list(map(int,input().split()))
    mnx = mny = 1000000000
    mxx = mxy = -1000000000
    for i in t:
        x, y = s[i-1][0], s[i-1][1]
        mnx = min(mnx, x)
        mxx = max(mxx, x)
        mny = min(mny, y)
        mxy = max(mxy, y)
    cnt = 0
    for x, y in s:
        if mnx <= x <= mxx and mny <= y <= mxy:
            cnt += 1
    print(cnt)
    print()