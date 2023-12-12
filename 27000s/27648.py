n, m, k = map(int, input().split())
if n+m > k+1:
    print('NO')
else:
    print('YES')
    c = 1
    for i in range(n):
        for j in range(m):
            print(c, end=' ')
            c += 1
        c = i+2
        print()
