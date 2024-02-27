for _ in range(int(input())):
    a = int(input())
    b = int(input())
    c = int(input())
    d = []
    e = []
    f = []
    for i in range(a):
        d.append(input())
    for i in range(b):
        e.append(input())
    for i in range(c):
        f.append(input())
    for i in range(a):
        for j in range(b):
            for k in range(c):
                print(d[i] + " " + e[j] + " " + f[k] + ".")
    print()
