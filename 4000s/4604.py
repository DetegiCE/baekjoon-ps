b = []
while True:
    a = input()
    if a == '#': break
    if a == '*':
        t = ''
        p = ''
        c = 0
        f = ''.join(b)
        for j in f:
            if j == ' ': c += 1
            elif c > 0:
                if c % 2 == 0: t += '1'
                else: t += '0'
                c = 0
        if len(t) % 5 > 0:
            t += '0' * (5 - len(t) % 5)
        for i in range(0, len(t), 5):
            p += ' ABCDEFGHIJKLMNOPQRSTUVWXYZ\',-.?'[int(t[i:i+5],2)]
        print(p)
        b.clear()
    else:
        b.append(a)