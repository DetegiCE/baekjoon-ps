while True:
    n, m, k = map(int, input().split())
    if n == 0 and m == 0 and k == 0: break
    a = [i for i in range(1, n+1)]
    for i in range(k):
        for j in range(m-1):
            a.append(a[0])
            a.pop(0)
        if i == k-1:
            print(a[0])
        a.pop(0)