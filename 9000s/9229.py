a = []
while True:
    b = input()
    if b == '#':
        if len(a) == 0:
            break
        n = len(a)
        c = True
        for i in range(n-1):
            if len(a[i]) != len(a[i+1]):
                c = False
                break
            d = 0
            for j in range(len(a[i])):
                if a[i][j] != a[i+1][j]:
                    d += 1
            if d != 1:
                c = False
                break
        if c:
            print('Correct')
        else:
            print('Incorrect')
        a = []
        continue
    else:
        a.append(b)
