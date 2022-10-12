while True:
    n = int(input())
    if n == 0:
        break
    a = []
    for i in range(n):
        a.append(int(input()))
    s = 0
    mx = max(a)
    for i in range(n):
        s = max(s + a[i], a[i])
        mx = max(mx, s)
    print(mx)
    