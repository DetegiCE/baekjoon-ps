t = int(input())
for _ in range(t):
    c, n = map(int, input().split())
    a = list(map(int, input().split()))

    s = 0
    sc = 0
    cnt = 0
    for i in a:
        if s + i > c: break
        s += i
        cnt += 1
        sc += s
    
    s1 = 0
    sc1 = 0
    cnt1 = 0
    a1 = sorted(a)
    for i in a1:
        if s1 + i > c: break
        s1 += i
        cnt1 += 1
        sc1 += s1
    
    s2 = 0
    sc2 = 0
    cnt2 = 0
    a2 = reversed(sorted(a))
    for i in a2:
        if s2 + i > c: break
        s2 += i
        cnt2 += 1
        sc2 += s2
    
    mx = max(cnt, cnt1, cnt2)
    cnd = dict()
    if cnt == mx: cnd['Bill'] = (cnt, sc)
    if cnt1 == mx: cnd['Steve'] = (cnt1, sc1)
    if cnt2 == mx: cnd['Linus'] = (cnt2, sc2)
    mxsc = min(r[1] for r in cnd.values())
    tt = [i for i, j in cnd.items() if j[1] == mxsc]
    if len(tt) == 1:
        wnnm = tt[0]
    else:
        wnnm = 'Steve'
    
    msol = 0
    msc = 0
    if wnnm == 'Bill': msol, msc = cnt, sc
    if wnnm == 'Steve': msol, msc = cnt1, sc1
    if wnnm == 'Linus': msol, msc = cnt2, sc2
    print(f'Scenario #{_+1}:')
    print(f'{wnnm} wins with {msol} solved problems and a score of {msc}.\n')