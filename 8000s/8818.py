for _ in range(int(input())):
    a=int(input())
    d = 0
    for i in range(64):
        if a == 2**i:
            print(0)
            d = 1
            break
    if d == 1:
        continue
    c = 0
    f = 0
    while a >= 1:
        if a % 2 == 1:
            f = 1
        if f == 1:
            c += 1
        a //= 2
    print(c)