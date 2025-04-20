n = int(input())
for _ in range(n):
    a = input().lower()
    b = 0
    c = 0
    for i in a:
        if i == 'p' and b == 0:
            b = 1
        if i == 'l' and b == 1:
            b = 2
        if i == 'u' and b == 2:
            b = 3
        if b == 3:
            c += 1
            b = 0
    print(c)