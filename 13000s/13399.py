n, m = map(int, input().split())
a = [int(input()) for _ in range(m)]

chk = [False for _ in range(n+1)]
for i in range(m-1, -1, -1):
    if not chk[a[i]]:
        chk[a[i]] = True
        print(a[i])
for i in range(1, n+1):
    if not chk[i]:
        print(i)