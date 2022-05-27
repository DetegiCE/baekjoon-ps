n = int(input())
a = list(map(int, input().split()))
negs = list()
cnt = 0
for i in range(n):
    if a[i] < 0:
        negs.append(i)
while len(negs) > 0:
    val = negs[-1]
    negs.pop()
    a[val] *= -1
    cnt += 1
    if val == 0:
        if a[1] >= 0 and a[1] - a[val] < 0:
            negs.append(1)
        a[1] -= a[val]
        if a[n-1] >= 0 and a[n-1] - a[val] < 0:
            negs.append(n-1)
        a[n-1] -= a[val]
    elif val == n-1:
        if a[0] >= 0 and a[0] - a[val] < 0:
            negs.append(0)
        a[0] -= a[val]
        if a[n-2] >= 0 and a[n-2] - a[val] < 0:
            negs.append(n-2)
        a[n-2] -= a[val]
    else:
        if a[val+1] >= 0 and a[val+1] - a[val] < 0:
            negs.append(val+1)
        a[val+1] -= a[val]
        if a[val-1] >= 0 and a[val-1] - a[val] < 0:
            negs.append(val-1)
        a[val-1] -= a[val]
print(cnt)