while True:
    a = int(input())
    if a == -1: break
    cnt = 0
    print(f'N={a}:')
    if a % 1111 == 0 or a > 9999 or a < 1000:
        print('No!!')
        continue
    while True:
        b = ''.join(sorted(str(a))).lstrip('0')
        c = ''.join(sorted(str(a), reverse=True))
        a = int(c) - int(b)
        print(f'{c}-{b}={a}')
        cnt += 1
        if a == 0 or a == 6174:
            print(f'Ok!! {cnt} times')
            break