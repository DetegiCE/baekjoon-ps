for i in range(1, int(input())+1):
    print(f'Data Set {i}:')
    n, m = map(int, input().split())
    d = {}
    for _ in range(n):
        a, b = input().split()
        d[a] = int(b)
    c = input().split()
    cnt = c.count('?')
    s = 0
    for i in c:
        if i == '?': continue
        s += d[i]
    p = list(d.values())
    for i in c:
        if i == '?': continue
        p.remove(d[i])
    p.sort()
    if cnt == 0:
        print(s, s)
    else:
        print(s+sum(p[:cnt]), s+sum(p[-cnt:]))
    print()
