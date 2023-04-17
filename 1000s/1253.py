neg = []
pos = []
n = int(input())
a = sorted(list(map(int, input().split())))
c = 0
for i in range(n):
    lef = 0
    rig = n-1
    while lef < rig:
        if lef == i:
            lef += 1
            continue
        if rig == i:
            rig -= 1
            continue
        s = a[lef] + a[rig]
        if s < a[i]:
            lef += 1
        elif s > a[i]:
            rig -= 1
        else:
            c += 1
            break
print(c)
