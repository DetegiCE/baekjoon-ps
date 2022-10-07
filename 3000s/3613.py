u = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
a = input()
if a[-1] == '_' or a[0] == '_':
    print('Error!')
    quit()
for i in range(1, len(a)):
    if a[i-1] == a[i] == '_':
        print('Error!')
        quit()
if '_' in a:
    b = a.split('_')
    for i in b:
        for j in i:
            if j in u:
                print('Error!')
                quit()
    print(b[0],end='')
    for i in range(1, len(b)):
        print(b[i].capitalize(), end='')
else:
    if a[0] in u:
        print('Error!')
        quit()
    b = []
    t = ''
    for i in a:
        if i in u:
            b.append(t)
            t = i.lower()
        else:
            t += i
    if len(b) > 0 and t:
        b.append(t)
    if len(b) == 0:
        print(t)
    else:
        print('_'.join(b))
    