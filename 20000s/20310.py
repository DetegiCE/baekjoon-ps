a = input()
zc = a.count('0')//2
oc = a.count('1')//2
for i in a:
    if i == '0' and zc > 0:
        print('0', end='')
        zc -= 1
    if i == '1':
        if oc > 0:
            oc -= 1
        else:
            print('1', end='')