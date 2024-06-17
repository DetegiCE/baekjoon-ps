def f():
    n = int(input())
    a = list(map(int, input().split()))
    c = 0
    
    for i in range(n):
        if a[i] % 2 == 1:
            a[i] += 1
    
    while True:
        flg = True
        for i in range(n-1):
            if a[i] != a[i+1]:
                flg = False
        if flg: break
        c += 1
        
        tmp = [a[n-1]//2]
        for i in range(n-1):
            tmp.append(a[i] // 2)
        for i in range(n):
            a[i] = a[i] // 2 + tmp[i]
        for i in range(n):
            if a[i] % 2 == 1:
                a[i] += 1
    print(c)

for _ in range(int(input())):
    f()
