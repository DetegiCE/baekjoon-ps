tc = 0
while True:
    n = int(input())
    if n == 0:
        break
    tc += 1
    b = [False for _ in range(26)]
    print(f'Program #{tc}')
    b[0] = True
    for i in range(n):
        x, y, z = input().split()
        p = ord(x) - 97
        q = ord(z) - 97
        b[p] = b[q]

    f = False
    for i in range(26):
        if b[i]:
            f = True
            print(chr(i+97), end=' ')
    if f: print()
    if not f:
        print('none')
    print()