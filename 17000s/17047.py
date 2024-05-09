def f(tim):
    h = int(tim[:2]) * 1000 * 60 * 60
    m = int(tim[3:5]) * 1000 * 60
    s = int(tim[6:8]) * 1000
    t = int(tim[9:12])
    return h + m + s + t

def f2(tim):
    t = tim % 1000
    s = tim // 1000 % 60
    m = tim // 60000 % 60
    h = tim // 3600000
    return '%02d:%02d:%02d,%03d' % (h, m, s, t)

g = []
while True:
    a = input()
    b = input().split(' --> ')
    c = input()
    d = ''
    flg = 0
    while True:
        e = input()
        if len(e) == 0:
            flg = 1
            break
        if e == '#':
            d += e + '\n'
            flg = 2
            break
        d += e + '\n'
    g.append([a, b, c, d])
    if flg == 2:
        break
q = int(input())

for i in g:
    print(i[0])
    t1 = f(i[1][0]) + q 
    t2 = f(i[1][1]) + q
    print(f2(t1), '-->', f2(t2))
    print(i[2])
    print(i[3])
