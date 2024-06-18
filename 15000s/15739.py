n = int(input())
a = []
chk = []
for i in range(n):
    b = list(map(int, input().split()))
    a.append(b)
    chk.extend(b)
chk.sort()
for i in range(1, n*n+1):
    if chk[i-1] != i:
        print('FALSE')
        exit(0)
s = n * (n**2 + 1) // 2
for i in range(n):
    if sum(a[i]) != s:
        print('FALSE')
        exit(0)
for j in range(n):
    t = 0
    for i in range(n):
        t += a[i][j]
    if t != s:
        print('FALSE')
        exit(0)
t = 0
for i in range(n):
    t += a[i][i]
if t != s:
    print('FALSE')
    exit(0)
t = 0
for i in range(n):
    t += a[i][n-i-1]
if t != s:
    print('FALSE')
    exit(0)
print('TRUE')
    
