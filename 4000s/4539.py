for _ in range(int(input())):
    n = list(map(int, input()))
    if len(n) == 1:
        print(n[0])
        continue
    l = len(n)
    for i in range(l-1, 0, -1):
        if n[i] >= 5:
            n[i-1] = n[i-1] + 1
        n[i] = 0
    print(*n, sep='')
