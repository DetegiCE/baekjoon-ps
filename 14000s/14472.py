n, m, d = map(int, input().split())
a = [list(input()) for _ in range(n)]
c = 0
if m >= d:
    for i in range(n):
        for j in range(m-d+1):
            if ''.join(a[i][j:j+d]) == '.'*d:
                c += 1

e = list(map(list, zip(*a)))
if n >= d:
    for i in range(m):
        for j in range(n-d+1):
            if ''.join(e[i][j:j+d]) == '.'*d:
                c += 1
print(c)
