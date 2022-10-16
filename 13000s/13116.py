for _ in range(int(input())):
    a, b = map(int, input().split())
    c, d = bin(a)[2:], bin(b)[2:]
    s = 0
    for i in range(min(len(c), len(d))):
        if c[i] == d[i]:
            s *= 2
            s += (c[i] == '1')
        else:
            break
    print(s*10)