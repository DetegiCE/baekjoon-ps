for _ in range(int(input())):
    n, k = map(int, input().split())
    a = []
    for i in range(k):
        a.append(input())
    s = a[0]
    for i in range(1, k):
        flg = 0
        for j in range(n, 0, -1):
            if s[-j:] == a[i][:j]:
                flg = 1
                s += a[i][j:]
                break
        if flg == 0:
            s += a[i]
    print(len(s))
