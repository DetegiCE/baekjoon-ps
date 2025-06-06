n, k = map(int, input().split())
a = list(map(int, input().split()))
lef = 0
rig = 1
mx = 1
cnt = [0 for _ in range(max(a)+1)]
cnt[a[0]] = 1
while rig < n:
    # print(lef, rig, cnt)
    if cnt[a[rig]] < k:
        cnt[a[rig]] += 1
        rig += 1
        mx = max(mx, rig - lef)
    else:
        cnt[a[lef]] -= 1
        lef += 1
        mx = max(mx, rig - lef)
print(mx)