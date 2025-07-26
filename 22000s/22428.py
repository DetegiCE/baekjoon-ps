while True:
    n = int(input())
    if n == 0: break
    a = input().split()

    l = 'F'
    r = 'F'
    t = 'FF'
    cnt = 0

    for i in a:
        if i == 'lu': l = 'P'
        elif i == 'ru': r = 'P'
        elif i == 'ld': l = 'F'
        elif i == 'rd': r = 'F'

        if l == r:
            cur = l + r
            if cur != t:
                cnt += 1
                t = cur
    print(cnt)