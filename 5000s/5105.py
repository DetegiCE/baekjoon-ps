while True:
    a = input()
    if a == '#':
        break
    a = a.split()
    v = []
    for i in range(21):
        v.append(0)
    s = int(a[0])
    v[s] = 1
    f = 0
    for i in a[1:]:
        if i[0] == 'U':
            s += int(i[1])
        else:
            s -= int(i[1])
        if not 1 <= s <= 20 or v[s] == 1:
            print('illegal')
            f = 1
            break
        v[s] = 1
    if f == 0:
        for i in range(1, 21):
            if v[i] == 0:
                print(i, end=' ')
        if sum(v) == 20:
            print('none', end='')
        print()
