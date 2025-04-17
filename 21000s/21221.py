n, m = map(int, input().split())
a = [list(input()) for _ in range(n)]
for i in range(n-1):
    for j in range(m-1):
        if a[i][j] == '#':
            if a[i+1][j] == '.':
                a[i+1][j] = '@'
            if a[i][j+1] == '.':
                a[i][j+1] = '@'
            if a[i+1][j+1] == '.':
                a[i+1][j+1] = '@'
for i in range(n):
    for j in range(m):
        if a[i][j] == '.': print('.', end='')
        else: print('#', end='')
    print()