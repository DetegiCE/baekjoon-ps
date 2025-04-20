n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = dict()
for i in range(n):
    c = a[i] - b[i]
    if c in d: d[c] += 1
    else: d[c] = 1
print(max(d.values()))