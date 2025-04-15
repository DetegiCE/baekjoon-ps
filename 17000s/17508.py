n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
if (n%2+m%2==2) and a[n//2][m//2] != '8':
    print(-1)
    exit(0)
d = 0
for i in range(n):
    for j in range(m):
        b = a[i][j]
        c = a[n-i-1][m-j-1]
        if b in '69':
            if c not in '69':
                print(-1)
                exit(0)
            if b == c: d += 1
        else:
            if b != c:
                print(-1)
                exit(0)
            if b == '7': d += 1
print(d // 2)