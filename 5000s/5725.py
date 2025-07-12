while True:
    t = int(input())
    if t == 0: break
    a = []
    for i in range(t):
        a.append(list(map(int, input().split()))+[i+1])
    for i in range(t):
        a[i][2] += a[i][1]
    a.sort(key=lambda x: x[2])
    f = 0
    for i in range(t-1):
        if a[i][2] == a[i+1][2]:
            print(-1)
            f = 1
            break
    if f == 1:
        continue
    for i in range(t):
        if a[i][2] != i+1:
            print(-1)
            f = 1
            break
    if f == 1:
        continue
    for i in a:
        print(i[0], end=' ')
    print()