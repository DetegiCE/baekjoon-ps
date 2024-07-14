while True:
    a = input()
    if a == '0':
        break
    b = list(map(int, a.split()))
    c = []
    for i in range(20):
        c.append('.')
    h = b[1:] * 20
    v = 0
    flg = 0
    for i in range(20):
        if c[i] != '.':
            continue
        cur = i
        while cur < 20:
            c[cur] = chr(v + 65)
            if cur + h[cur] < 20:
                if c[cur+h[cur]] != '.':
                    flg = 1
                    break
            cur += h[cur]
        if flg == 1:
            break
        v += 1
    if flg == 1:
        print('CRASH')
    else:
        print(''.join(c))
