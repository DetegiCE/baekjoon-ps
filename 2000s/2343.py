n, m = map(int, input().split())
vid = list(map(int, input().split()))
lef = max(vid)
rig = 1000000000
minv = 1000000000
while lef <= rig:
    mid = (lef + rig) // 2
    cnt = 1
    tsum = vid[0]
    for i in range(1, n):
        if tsum + vid[i] > mid:
            cnt+=1
            tsum = vid[i]
        else:
            tsum += vid[i]
    if cnt > m:
        lef = mid + 1
    else:
        minv = min(minv, mid)
        rig = mid - 1
    # print(lef, rig, mid, minv)
print(minv)
