s = 0
while True:
    n, m, c = map(int, input().split())
    if n == 0 and m == 0 and c == 0: break
    s += 1
    print(f'Sequence {s}')
    a = [0]
    chk = [False for _ in range(n+1)]
    cur = 0
    mx = 0
    bl = False
    for i in range(n):
        a.append(int(input()))
    d = [int(input()) for _ in range(m)]
    for i in range(m):
        if chk[d[i]]:
            chk[d[i]] = False
            cur -= a[d[i]]
        else:
            chk[d[i]] = True
            cur += a[d[i]]
        if cur > c:
            bl = True
            break
        mx = max(mx, cur)
    if bl: print('Fuse was blown.')
    else:
        print('Fuse was not blown.')
        print(f'Maximal power consumption was {mx} amperes.')
    print()