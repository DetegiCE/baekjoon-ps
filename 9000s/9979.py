b = []
while True:
    try:
        a = input()
        if a == 'START':
            continue
        if a == 'END':
            b.sort()
            for i in b[::-1]:
                print(i[1])
            print()
            b = []
            continue
        c = a.split()
        b.append([int(c[2])-int(c[1]), c[0]])
    except:
        break