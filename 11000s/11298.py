for _ in range(int(input())):
    a, b = map(int, input().split())
    c = []
    for i in range(1, 11):
        c.append(a * i + b)
    m = max(c)
    print(f'y = {a}x + {b}')
    for i in range(m, 0, -1):
        print('*', end='')
        if i in c:
            for j in range(10):
                if c[j] == i: print('*', end='')
                else: print(' ', end='')
        else: print(' ' * 10, end='')
        print()
    print('*' * 11)