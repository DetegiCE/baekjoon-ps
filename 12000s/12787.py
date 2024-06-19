for _ in range(int(input())):
    a, b = input().split()
    if a == '1':
        b = b.split('.')
        for i in range(8):
            b[i] = int(b[i])
        c = 1
        s = 0
        for i in range(7, -1, -1):
            s += b[i] * c
            c *= 256
        print(s)
    else:
        b = int(b)
        c = []
        for i in range(8):
            c.append(str(b % 256))
            b //= 256
        print('.'.join(c[::-1]))
