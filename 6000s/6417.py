while True:
    n = int(input())
    if n == -1:
        break
    ans = -1
    for i in range(n-1, 1, -1):
        cur = n
        f = 0
        for j in range(i):
            cur -= 1
            if cur < 0: break
            if cur % i != 0: break
            cur //= i
            cur *= (i-1)
            f += 1
        if f == i:
            ans = i
            break
    print(f'{n} coconuts, ', end='')
    if ans == -1:
        print('no solution')
    else:
        print(f'{ans} people and 1 monkey')