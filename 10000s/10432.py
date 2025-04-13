n = int(input())
for _ in range(n):
    a = list(map(int, input().split()))
    print(a[0], end=' ')
    a = a[1:]
    c = 0
    while True:
        mx = max(a)
        if mx == 0:
            break
        for i in range(len(a)-1):
            if a[i] == mx:
                if a[i+1] == mx:
                    a[i] = a[i-1]
                    continue
                else:
                    c += 1
                    a[i] = a[i-1]
    print(c)