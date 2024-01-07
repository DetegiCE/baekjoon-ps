for _ in range(int(input())):
    a = ''
    while True:
        b = input()
        if len(b) == 0:
            break
        a += b
    t = len(a)
    r = a.count('#')
    v = round((t-r)/t*100, 1)
    if str(v).split('.')[-1] == '0':
        v = int(v)
    print(f'Efficiency ratio is {v}%.')
