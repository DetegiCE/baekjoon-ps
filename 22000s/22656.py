while True:
    n,m,p=map(int,input().split())
    if n == 0 and m == 0 and p == 0:
        break
    a = []
    for i in range(n):
        a.append(int(input()))
    if a[m-1] == 0:
        print(0)
        continue
    t = sum(a) * (100-p) / a[m-1]
    print(int(t))