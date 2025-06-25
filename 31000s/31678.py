def chk(p):
    for i in range(5):
        if sum(p[i]) == -5:
            return True
    for i in range(5):
        if p[0][i] + p[1][i] + p[2][i] + p[3][i] + p[4][i] == -5:
            return True
    s = 0
    t = 0
    for i in range(5):
        s += p[i][i]
    for i in range(5):
        t += p[i][4-i]
    if s == -5 or t == -5:
        return True
    return False

d = dict()
for _ in range(int(input())):
    a = input()
    b = []
    for i in range(5):
        b.append(list(map(int, input().split())))
    d[a] = b
c = int(input())
e = list(map(int, input().split()))
f = []
for i in d:
    n = i
    p = d[i]
    for j in e:
        for k in range(5):
            for l in range(5):
                if p[k][l] == j:
                    p[k][l] = -1
    if chk(p):
        f.append(n)
print(len(f))
for i in f:
    print(i)