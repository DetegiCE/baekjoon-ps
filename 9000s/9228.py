while True:
    a = input()
    if a == '#':
        break
    o = a
    a = a[::-1]
    c = 2
    s = 0
    for i in a:
        s += c * int(i)
        c += 1
    s %= 11
    s = 11 - s
    if s == 10:
        print(f'{o} -> Rejected')
    elif s == 11:
        print(f'{o} -> 0')
    else:
        print(f'{o} -> {s}')