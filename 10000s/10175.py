for _ in range(int(input())):
    a, b = input().split()
    bc = b.count('B') * 2
    cc = b.count('C')
    mc = b.count('M') * 4
    wc = b.count('W') * 3
    mx = max(bc, cc, mc, wc)
    if [bc, cc, mc, wc].count(mx) > 1:
        print(f'{a}: There is no dominant species')
    else:
        mxv = ''
        if mx == bc: mxv = 'Bobcat'
        if mx == cc: mxv = 'Coyote'
        if mx == mc: mxv = 'Mountain Lion'
        if mx == wc: mxv = 'Wolf'
        print(f'{a}: The {mxv} is the dominant species')
