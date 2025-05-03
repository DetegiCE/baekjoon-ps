t = int(input())
for _ in range(t):
    n = int(input())
    m = {'shirt':[],'pants':[],'socks':[]}
    for i in range(n):
        a, b = input().split('(')
        b = b[:-1]
        a = a[:-1]
        m[b].append(a)
    while m['shirt'] and m['pants'] and m['socks']:
        print(f"{m['shirt'][-1]}, {m['pants'][-1]}, {m['socks'][-1]}")
        m['shirt'].pop()
        m['pants'].pop()
        m['socks'].pop()
    print()