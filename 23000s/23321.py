a = input()
b = input()
c = input()
d = []
for i in a:
    d.append(0)
for i in range(len(a)):
    if a[i] == 'o':
        d[i] = 1
    if b[i] == 'o':
        d[i] = 2
    if c[i] == 'o':
        d[i] = 3
for i in range(5):
    for j in range(len(a)):
        if d[j] == 1:
            if i == 0: print('.', end='')
            if i == 1: print('o', end='')
            if i == 2: print('m', end='')
            if i == 3: print('l', end='')
            if i == 4: print('n', end='')
        if d[j] == 2:
            if i == 0: print('o', end='')
            if i == 1: print('w', end='')
            if i == 2: print('l', end='')
            if i == 3: print('n', end='')
            if i == 4: print('.', end='')
        if d[j] == 3:
            if i == 0: print('.', end='')
            if i == 1: print('.', end='')
            if i == 2: print('o', end='')
            if i == 3: print('L', end='')
            if i == 4: print('n', end='')
    print()
