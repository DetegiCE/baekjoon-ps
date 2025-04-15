t = int(input())
for tc in range(1, t+1):
    print(f'Case #{tc}: ', end='')
    c, v, l = map(int, input().split())
    a = [0 for _ in range(l+1)]
    a[0] = 1
    a[1] = v
    for i in range(2, l+1):
        a[i] = v * (a[i-1] + c * a[i-2]) % int(1e9+7)
    print(a[l])