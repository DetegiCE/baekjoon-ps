m, n = map(int, input().split())
u, l, r, d = map(int, input().split())
a = []
for i in range(m):
    a.append(input())
f = lambda x, y: '#.'[(x+y)%2]
for i in range(m+u+d):
    for j in range(n+l+r):
        if i < u: print(f(i, j), end='')
        elif i >= u+m: print(f(i, j), end='')
        elif j < l: print(f(i, j), end='')
        elif j >= l+n: print(f(i, j), end='')
        else:
            print(a[i-u][j-l], end='')
    print()
