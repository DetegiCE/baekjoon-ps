while True:
    try:
        a, b = input().split()
        alen = len(a)
        blen = len(b)
        if alen > blen:
            print('No')
            continue
        apos = 0
        nocheck = 1
        for i in range(blen):
            if a[apos] == b[i]:
                apos+=1
            if apos == alen:
                nocheck = 0
                break
        if nocheck == 0:
            print('Yes')
        else: print('No')
    except:
        break
        