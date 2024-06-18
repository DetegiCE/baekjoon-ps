def f():
    n, k = map(int, input().split())
    if n == 1:
        print(k)
        return
    lp = k // ((n-1)*2)
    rm = k - lp * (n-1) * 2
    a = [lp] + ([lp*2] * (n-2)) + [lp]
    
    for i in range(rm):
        if i <= n-1:
            a[i] += 1
        else:
            pos = n-2-(i-n)
            a[pos] += 1
    
    for i in a:
        print(i, end=' ')
    print()
        
for _ in range(int(input())):
    f()
