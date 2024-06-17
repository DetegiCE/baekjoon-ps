a='1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./ '
b='`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. '
d = dict(zip(a, b))
while True:
    try:
        c = input()
        for i in c:
            print(d[i], end='')
        print()
    except:
        break
