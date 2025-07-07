while True:
    a, b = map(int, input().split())
    if a == 0: break
    r, c = 0, 0
    s = 0
    for i in range(a):
        d = input()
        for j in range(b):
            r += (i+1) * int(d[j])
            c += (j+1) * int(d[j])
            s += int(d[j])
    print(r/s, c/s)