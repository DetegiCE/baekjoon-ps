def checkzero(a):
    return sum(a) == 0

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    while True:
        if checkzero(a):
            print('ZERO')
            break
        b.append(a)
        c = []
        for i in range(n):
            c.append(abs(a[i-1]-a[i]))
        a = c
        flg2 = 0
        for i in b:
            flg = 0
            for j in range(n):
                if a[j] != i[j]:
                    flg = 1    
                    break
            if flg == 0:
                print('LOOP')
                flg2 = 1    
                break
        if flg2 == 1:
            break