a = []
for _ in range(9):
    b, c, d = input().split()
    c, d = int(c), int(d)
    a.append([_, b, c, d])
for _ in range(9):
    b, c = map(int, input().split())
    a[_][2] += b
    a[_][3] += c
mx = 0
mxi = -1
for i in range(9):
    if mx < a[i][2]/a[i][3]:
        mx = a[i][2]/a[i][3]
        mxi = i
if mxi < 3:
    a[mxi], a[3] = a[3], a[mxi]
    for i in a:
        print(i[1])
else:
    for i in range(3):
        print(a[i][1])
    print(a[mxi][1])
    for i in range(3, 9):
        if mxi == i: continue
        print(a[i][1])