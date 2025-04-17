t = int(input())
for i in range(t):
    n = int(input())
    a = []
    for j in range(n):
        b, c = input().split()
        a.append([-int(c), b])
    a.sort()
    print(*list(map(lambda x: x[1], a)), sep=', ')