d = {'1':' .,!?','2':'cab','3':'fde','4':'igh',
     '5':'ljk','6':'omn','7':'spqr','8':'vtu',
     '9':'zwxy'}
for _ in range(int(input())):
    a = input()
    while a:
        b = a[0]
        c = len(a) - len(a.lstrip(b))
        a = a.lstrip(b)
        if b == '0':
            continue
        print(d[b][c%len(d[b])], end='')
    print()