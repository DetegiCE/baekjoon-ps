n, k = map(int, input().split())
a = list(map(int, input().split()))

lef = 0
b = 0
c = 0
d = 1e18

for rig in range(n):
    if a[rig] == 0:
        b += 1
    else:
        c += 1

    while b >= k:
        d = min(d, c)
        if a[lef] == 0:
            b -= 1
        else:
            c -= 1
        lef += 1

if d == 1e18:
    print("NIE")
else:
    print(d)
