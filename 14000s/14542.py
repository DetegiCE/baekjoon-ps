c = 0
while True:
    n = int(input())
    c += 1
    if n == 0:
        break
    s = 0
    for i in range(n):
        if i == 0:
            s += int(input())
        elif i == n-1:
            s += sum(list(map(int, input().split())))
        else:
            a = list(map(int, input().split()))
            s += (a[0] + a[-1])
    print(f'Case #{c}:{s}')