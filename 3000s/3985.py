l = int(input())
n = int(input())
m = 0
mv = -1
pos = []
cnt = []
mika = []
for _ in range(n):
    lef, rig = map(int, input().split())
    pos.append([lef, rig])
    cnt.append(0)
    if rig-lef+1 > m:
        m = rig-lef+1
        mv = _+1
print(mv)
for i in range(l+1):
    mika.append(0)
for i in range(n):
    lef, rig = pos[i][0], pos[i][1]
    for j in range(lef, rig+1):
        if mika[j] == 0:
            mika[j] = i+1
            cnt[i] += 1
mxv = max(cnt)
print(cnt.index(mxv)+1)
