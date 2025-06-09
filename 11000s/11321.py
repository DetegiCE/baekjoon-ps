while True:
    a = input()
    if a == '0':
        break
    b = list(map(int, a.split('+')))
    c = [[] for _ in range(10)]
    for i in b:
        c[i%10].append(i)
    d = []
    while len(c[0]) > 1:
        d.append(c[0][-1])
        c[0].pop()
        d.append(c[0][-1])
        c[0].pop()
    while len(c[5]) > 1:
        d.append(c[5][-1])
        c[5].pop()
        d.append(c[5][-1])
        c[5].pop()
    for i in [(1,9),(2,8),(3,7),(4,6)]:
        while c[i[0]] and c[i[1]]:
            d.append(c[i[0]][-1])
            c[i[0]].pop()
            d.append(c[i[1]][-1])
            c[i[1]].pop()
    for i in range(10):
        while c[i]:
            d.append(c[i].pop())
    print('+'.join(list(map(str,d))))