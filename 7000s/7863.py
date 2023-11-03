n, p = map(int, input().split())
simp = []
hard = []
for i in range(p):
    simp.append(0)
    hard.append(0)
for i in range(n):
    a = list(map(int, input().split()))
    mn = min(a)
    mx = max(a)
    for j in range(p):
        if a[j] == mn:
            simp[j] += 1
        if a[j] == mx:
            hard[j] += 1
ans = []
for i in range(p):
    if simp[i] > n//2 and hard[i] == 0:
        ans.append(i+1)
if len(ans) == 0:
    print(0)
else:
    print(*ans)
