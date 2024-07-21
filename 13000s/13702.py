n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))
lef = 1
rig = max(a)
mx = 0
while lef <= rig:
    mid = (lef + rig) // 2
    cnt = 0
    for i in range(n):
        cnt += a[i] // mid
    if cnt >= k:
        mx = max(mx, mid)
        lef = mid + 1
    else:
        rig = mid - 1
print(mx)