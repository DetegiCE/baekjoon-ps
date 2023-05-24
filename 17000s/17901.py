n = int(input())
d = {}
a = list(map(int, input().split()))
for i in range(n):
    if a[i] not in d:
        d[a[i]] = []
    d[a[i]].append(i)
mn = n
for i in d.values():
    for j in range(len(i)-1):
        mn = min(mn, i[j+1]-i[j])
print(mn)
