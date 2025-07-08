p = [2, 3, 5, 7]
for i in range(11, 1000, 2):
    j = 0
    f = 0
    while p[j]**2 <= i:
        if i % p[j] == 0:
            f = 1
            break
        j += 1
    if f == 0:
        p.append(i)
l = len(p)
for _ in range(int(input())):
    t = int(input())
    g = 0
    for i in range(l):
        for j in range(i, l):
            for k in range(j, l):
                if p[i] + p[j] + p[k] == t:
                    g = 1
                    print(p[i], p[j], p[k])
                    break
            if g == 1: break
        if g == 1: break
    if g != 1: print(0)