n, m = map(int, input().split())
mnv = -1
for _ in range(m):
    a, b = map(int, input().split())
    lef = 0
    rig = n
    cmn = a * n
    while lef <= rig:
        mid = (lef + rig) // 2
        flr = a * mid - b * (n - mid)
        if flr > 0:
            cmn = min(cmn, flr)
            rig = mid - 1
        else:
            lef = mid + 1
    if mnv == -1:
        mnv = cmn
    else:
        mnv = min(mnv, cmn)
print(mnv)
