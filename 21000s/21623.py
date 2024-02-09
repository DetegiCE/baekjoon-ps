k, n = map(int, input().split())
a = list(map(int, input().split()))
i = 0
p = n
r = 0
chk = False
for i in range(k):
    chk = True
    if p > a[i]:
        p -= a[i]
    elif p == a[i]:
        chk = False
        p = n
        r += 1
print(r)
if p == n and not chk: print(0)
else: print(p)
