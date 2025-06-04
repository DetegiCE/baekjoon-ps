t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for i in range(n):
        a.append(input())
    ans = 0
    for i in range(n):
        for j in range(n):
            if a[i][j] == '.':
                b = 0
                c = 1
                while True:
                    if i + c - 1 >= n or j + c - 1 >= n:
                        break
                    for k in range(i, i+c):
                        for l in range(j, j+c):
                            if a[k][l] == '#':
                                b += 1
                    if b > 0: break
                    if c*c > ans:
                        ans = c*c
                    c += 1
    print(ans)