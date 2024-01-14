c = 0
while True:
    n = int(input())
    if n == 0:
        break
    a = []
    for _ in range(n):
        a.append(input())
    c += 1
    print('SET', c)
    for i in range(0, n, 2):
        print(a[i])
    for i in range(n-(2 if n % 2 == 1 else 1), -1, -2):
        print(a[i])
