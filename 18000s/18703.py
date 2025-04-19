for _ in range(int(input())):
    n = int(input())
    d = dict()
    for i in range(n):
        a, b = input().split()
        b = int(b)
        if a in d: d[a] = min(d[a], b)
        else: d[a] = b
    c = list(d.items())
    c.sort(key=lambda x: x[1])
    for i in c:
        print(i[1], end=' ')
    print()