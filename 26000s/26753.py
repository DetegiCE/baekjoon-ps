a = input()
b = 0
c = 0
for i in a:
    if b == 0:
        if i == 'o':
            b = 1
    elif b == 1:
        if i == 'i':
            b = 2
    else:
        if i == 'j':
            c += 1
            b = 0
if c == 0: print('NIE')
else: print(c)