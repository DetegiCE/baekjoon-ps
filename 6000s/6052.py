def f(n):
    s = 1
    i = 2
    while i * i <= n:
        if i * i == n:
            s += i
            break
        if n % i == 0:
            s += i
            s += n//i
        i += 1
    return s

d = dict()
for i in range(int(input()), 100000):
    v = 0
    w = 0
    if i in d: v = d[i]
    else:
        v = f(i)
        d[i] = v
    if v in d: w = d[v]
    else:
        w = f(v)
        d[v] = w
    if w == i and i != v:
        print(i, v)
        break
