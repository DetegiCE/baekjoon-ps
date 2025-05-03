p, t = map(int, input().split())
a = [[] for _ in range(p+1)]
while True:
    try:
        d, e = map(int, input().split())
        a[d].append(e)
    except:
        break
for i in range(p+1):
    if a[i]:
        b = sorted(list(set(a[i])))
        a[i] = b
ans = 0
for i in range(1, p+1):
    if len(a[i]) == 1 and a[i][0] == -1:
        continue
    for j in range(i+1, p+1):
        if a[i] == a[j]:
            a[j] = [-1]
    ans += 1
print(ans)