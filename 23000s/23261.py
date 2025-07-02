t = int(input())
for tc in range(1, t+1):
    print(f'Case #{tc}: ', end='')
    n, d, c, m = map(int, input().split())
    s = input()
    b = -1
    for i in range(n):
        if s[i] == 'C':
            if c <= 0:
                b = i
                break
            c -= 1
        else:
            if d <= 0:
                b = i
                break
            d -= 1
            c += m
    if b == -1:
        print('YES')
    else:
        flg = 0
        for i in range(b, n):
            if s[i] == 'D':
                print('NO')
                flg = 1
                break
        if flg == 0:
            print('YES')