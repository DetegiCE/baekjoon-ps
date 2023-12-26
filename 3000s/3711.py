n = int(input())
for _ in range(n):
    g = int(input())
    a = []
    for i in range(g):
        a.append(int(input()))
    mx = max(a)
    i = 1
    while True:
        b = set()
        f = 0
        for j in range(g):
            if a[j] % i in b:
                f = 1
                break
            b.add(a[j] % i)
        if f == 0:
            print(i)
            break
        i += 1
