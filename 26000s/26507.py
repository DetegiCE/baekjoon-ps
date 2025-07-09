t = int(input())
a = []
for _ in range(t):
    b = []
    for i in range(10):
        b.append(input())
    input()
    a.append(b)
n = int(input())
for _ in range(n):
    c = list(map(int, input().split()))
    d = [[0 for _ in range(10)] for __ in range(10)]
    for k in c:
        for i in range(10):
            for j in range(10):
                d[i][j] += int(a[k][i][j])
    for i in range(10):
        for j in range(10):
            print(f'{d[i][j]:02d} ', end='')
        print()
    print()