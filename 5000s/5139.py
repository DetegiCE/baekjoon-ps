for i in range(int(input())):
    print(f'Data Set {i+1}:')
    a = []
    h, w = map(int,input().split())
    for _ in range(h):
        a.append(input())
    for j in range(w):
        xflag = 0
        s = 0
        for k in range(h):
            if a[k][j] == 'X':
                xflag = 1
                print(s, end=' ')
                break
            elif a[k][j] == 'H':
                s += 3
            else:
                s += 1
        if xflag == 0:
            print('N ', end='')
    print('\n')