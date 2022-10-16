for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    s = 0
    m = max(a)
    for i in a:
        s = max(s+i, i)
        m = max(s, m)
    print(m)