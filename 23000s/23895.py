t = int(input())
for tc in range(1, t+1):
    print(f'Case #{tc}: ', end='')
    n, l = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = 0
    f = 0
    for i in range(n):
        if b + a[i] > l:
            print(i)
            f = 1
            break
        b += a[i]
    if f == 0:
        print(n)