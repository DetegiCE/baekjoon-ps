n = int(input())
a = ' ' + input()
b = [0]
for i in range(1, n+1):
    if a[i] == '+':
        b.append(b[-1] + 1)
    elif a[i] == '-':
        b.append(b[-1] - 1)
    else:
        b.append(b[-1])
c = []
for i in range(1, n+1):
    if a[i] == '+': c.append(b[i-1])
    else: c.append(b[i])
mx = max(c)
mn = min(c)
for i in range(mx, mn-1, -1):
    for j in range(n):
        if c[j] == i:
            if a[j+1] == '+': print('/', end='')
            elif a[j+1] == '-': print('\\', end='')
            else: print('_', end='')
        else: print('.', end='')
    print()