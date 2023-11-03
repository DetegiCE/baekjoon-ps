while True:
    a, b = input().split()
    if a == '0':
        break
    print(b)
    a = int(a)
    tot = []
    buy = []
    sell = []
    for i in range(a):
        c = input().split()
        c[2] = float(c[2])
        tot.append([c[0], c[1], c[2]])
        if c[1] == 'buy':
            buy.append([c[0], c[2]])
        else:
            sell.append([c[0], c[2]])
    for i in range(a):
        print(f'{tot[i][0]}: ', end='')
        if tot[i][1] == 'buy':
            cnt = 0
            for j in sell:
                if j[1] <= tot[i][2]:
                    print(j[0], end=' ')
                    cnt += 1
            if cnt == 0:
                print('NO-ONE', end='')
            print()
        else:
            cnt = 0
            for j in buy:
                if j[1] >= tot[i][2]:
                    print(j[0], end=' ')
                    cnt += 1
            if cnt == 0:
                print('NO-ONE', end='')
            print()
