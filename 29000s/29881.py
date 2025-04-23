n = int(input())
d = dict()
for _ in range(n*2):
    a = input().split()
    if a[0] in d: d[a[0]].append(a[1])
    else: d[a[0]] = [a[1]]
for i in d:
    print(*sorted(d[i]))