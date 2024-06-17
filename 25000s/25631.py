n = int(input())
a = sorted(list(map(int, input().split())))
f = []
for i in range(n):
    f.append(0)
for i in range(n-1):
    for j in range(i+1, n):
        if a[i] < a[j] and f[j] == 0:
            f[j] = 1
            a[i] = 0
            break
ans = 0
for i in range(n):
    if a[i] != 0:
        ans += 1
print(ans)
