n = int(input())
d = list(map(int, input().split()))
d.sort()
s = sum(d)
a = []
for i in range(n-1, -1, -1):
    if not a or a[-1] != s - d[i]:
        a.append(s-d[i])
print(len(a))
print(*a)