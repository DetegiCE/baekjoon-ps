d1=list('QWERTYUIOASDFGHJKZXCVBN')
d2=list('WERTYUIOPSDFGHJKLXCVBNM')
d = dict(zip(d1, d2))
a = input()
for i in a:
    if i in d:
        print(d[i], end='')
    else: print(i, end='')