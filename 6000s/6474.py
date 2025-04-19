mr = 'AEHIJLMOSTUVWXYZ12358'
ms = 'A3HILJMO2TUVWXY51SEZ8'
md = dict(zip(mr, ms))
while True:
    try:
        a = input()
        m = ''
        for i in a:
            if i in md: m += md[i]
        if a == a[::-1]:
            if len(m) == len(a) and a == m[::-1]:
                print(a + ' -- is a mirrored palindrome.')
            else:
                print(a + ' -- is a palindrome.')
        else:
            if len(m) == len(a) and a == m[::-1]:
                print(a + ' -- is a mirrored string.')
            else:
                print(a + ' -- is not a palindrome.')
        print()
    except:
        break