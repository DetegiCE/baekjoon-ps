while True:
    a = input()
    if a == '#':
        break
    sm = []
    lg = []
    nu = []
    for i in a:
        if 65 <= ord(i) <= 90: lg.append(i)
        if 48 <= ord(i) <= 58: nu.append(i)
        if 97 <= ord(i) <= 122: sm.append(i)
    sm.sort()
    lg.sort()
    nu.sort()
    print(''.join(sm) + ''.join(lg) + ''.join(nu))