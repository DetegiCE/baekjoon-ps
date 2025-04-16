m, n = map(int, input().split())
d = dict()
for _ in range(m):
    a, b = input().split()
    d[a] = int(b)
for i in range(n):
    c = 0
    while True:
        a = input()
        if a == '.':
            print(c)
            break
        b = a.split()
        for i in b:
            if i in d:
                c += d[i]