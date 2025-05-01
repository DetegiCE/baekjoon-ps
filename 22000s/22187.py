a = input()
b = []
c = False
for i in a:
    if c:
        if i == ')':
            print(''.join(b[::-1]), end='')
            b = []
            c = False
        else:
            b.append(i)
    else:
        if i == '(':
            c = True
        else:
            print(i, end='')
