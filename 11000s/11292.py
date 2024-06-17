while True:
    n = int(input())
    if n == 0: break
    a = dict()
    for i in range(n):
        b, c = input().split()
        c = float(c)
        if c not in a:
            a[c] = [b]
        else:
            a[c].append(b)
    mx = max(a.keys())
    print(' '.join(a[mx]))
