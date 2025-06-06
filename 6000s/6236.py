n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
lef = max(a)
rig = sum(a)
while lef <= rig: 
    mid = (lef + rig) // 2
    c = 0
    s = 0
    for i in range(n):
        s += a[i]
        if s > mid:
            c += 1
            s = a[i]
        elif s == mid:
            c += 1
            s = 0
    if s != 0:
        c += 1
    if c > m:
        lef = mid + 1
    else:
        rig = mid - 1
    # print(mid, c)
print(mid)