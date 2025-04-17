for tc in range(int(input())):
    print(f'Case #{tc+1}:', end=' ')
    n, k = map(int, input().split())
    d = {n:1}
    c = 0
    while True:
        mx = max(d.keys())
        dmx = d[mx]
        c += dmx
        
        lef = (mx-1) // 2
        rig = mx - lef - 1
        if c >= k:
            print(rig, lef)
            break
        del d[mx]

        if lef not in d: d[lef] = 0
        if rig not in d: d[rig] = 0
        d[lef] += dmx
        d[rig] += dmx
    if c < k:
        print(0, 0)