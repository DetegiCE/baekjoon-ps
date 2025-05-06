for tc in range(1, int(input())+1):
    print(f'Case #{tc}: ', end='')
    p, k, l = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    c = 0
    for i in range(l):
        c += a[l-1-i] * (i//k+1)
    print(c)