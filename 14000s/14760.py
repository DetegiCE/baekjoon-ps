while True:
    n = int(input())
    if n == 0:
        break
    a = [input() for _ in range(n)]
    for i in range(n):
        f = 0
        b = 1 if a[i][0] == 'X' else 0
        for j in range(1, n):
            if a[i][j] == 'X':
                b += 1
            else:
                if b > 0: 
                    f = 1
                    print(b, end=' ')
                b = 0
        if b != 0 or f == 0:
            print(b, end=' ')
        print()
    for j in range(n):
        f = 0
        b = 1 if a[0][j] == 'X' else 0
        for i in range(1, n):
            if a[i][j] == 'X':
                b += 1
            else:
                if b > 0:
                    f = 1
                    print(b, end=' ')
                b = 0
        if b != 0 or f == 0:
            print(b, end=' ')
        print()