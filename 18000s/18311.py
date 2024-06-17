n, k = map(int, input().split())
a = list(map(int, input().split()))
chk = False
for i in range(n):
    k -= a[i]
    if k < 0:
        print(i+1)
        chk = True
        break

if not chk:
    for i in range(n-1, -1, -1):
        k -= a[i]
        if k < 0:
            print(i+1)
            break
