for _ in range(int(input())):
    n = int(input())
    a = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append([x, y])
    m = int(input())
    b = []
    for i in range(m):
        x, y = map(int, input().split())
        b.append([x, y])
    c = []
    for i in range(n):
        c.append(0)
    for i in range(m):
        for j in range(n):
            if b[i][0]-50 <= a[j][0] <= b[i][0] + 50 and \
                b[i][1]-50 <= a[j][1] <= b[i][1] + 50:
                c[j] = 1
    print(sum(c))
