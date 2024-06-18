a1 = 'aiyeou'
a2 = a1[3:]+a1[:3]
b1 = 'bkxznhdcwgpvjqtsrlmf'
b2 = b1[10:]+b1[:10]
a = dict(zip(a1, a2))
b = dict(zip(b1, b2))
while True:
    try:
        c = input()
        for i in c:
            if i in a1:
                print(a[i], end='')
            elif i in b1:
                print(b[i], end='')
            elif i in a1.upper():
                print(a[i.lower()].upper(), end='')
            elif i in b1.upper():
                print(b[i.lower()].upper(), end='')
            else:
                print(i, end='')
        print()
    except:
        break
