while True:
    n = int(input())
    if n == 0: break
    item = dict()
    for _ in range(n):
        a, b, c = input().split()
        b, c = int(b), int(c)
        item[a] = [b, c]
    m = int(input())
    cnt = 0
    for _ in range(m):
        a, b, c = map(int, input().split())
        s = 0
        e = 0
        for i in range(b):
            d = input()
            if item[d][1] <= c:
                s += item[d][0]
                e += 1
        if e == b:
            print(a, s)
        else:
            cnt += 1
            print(a, s, '*')
    print(f'Number of discontented customers is: {cnt}')
