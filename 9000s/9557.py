for _ in range(int(input())):
    n = int(input())
    a = input().split()
    l = []
    r = []
    chk = True
    e = ''
    for i in range(n):
        if a[i][0] == '#' and chk:
            l.append(a[i])
        elif a[i][0] != '#':
            chk = False
            e = a[i]
        else:
            r.append(a[i])
    for i in range(len(r)):
        if i != 0:
            print(' ', end='')
        print(r[i], end='')
    if len(r) > 0 and e != '':
        print(' ', end='')
    print(e, end='')
    if len(l) > 0 and e != '':
        print(' ', end='')
    for i in range(len(l)):
        if i != 0:
            print(' ', end='')
        print(l[i], end='')
    print()
