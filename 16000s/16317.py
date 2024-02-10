n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(366):
    b.append(0)
for i in a:
    b[i] += 1
d = 0
e = 0
ans = 0
for i in range(1, 366):
    d += b[i]
    e += d
    if e >= 20:
        ans += 1
        d = 0
        e = 0
if e > 0:
    ans += 1
print(ans)
