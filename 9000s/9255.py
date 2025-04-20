t = int(input())
for tc in range(1, t+1):
    print(f'Data Set {tc}:')
    n, m = map(int, input().split())
    lnk = [[] for _ in range(n+1)]
    for i in range(m):
        s, e = map(int, input().split())
        lnk[s].append(e)
        lnk[e].append(s)
    
    st = int(input())
    lnk[st].sort()
    for i in range(len(lnk[st])):
        if i > 0 and lnk[st][i-1] == lnk[st][i]: continue
        print(lnk[st][i], end=' ')
    print()
    print()