while True:
    try:
        a = input().split()
        b = []
        for i in range(len(a)):
            if a[i].lower()[0] in 'aeiou':
                b.append(a[i])
                a[i] = '!'
        bpos = 0
        b.reverse()
        for i in a:
            if i == '!':
                print(b[bpos], end=' ')
                bpos += 1
            else:
                print(i, end=' ')
        print()
    except:
        break