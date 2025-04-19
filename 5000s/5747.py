while True:
    n = int(input())
    if n == 0:
        break
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c, d = 0, 0
    for i in a: 
        if i % 2 == 0: c += 1
    for i in b: 
        if i % 2 == 1: d += 1
    print(abs(c-d))