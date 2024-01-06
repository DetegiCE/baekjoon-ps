for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = 1
    s = sum(a)
    while s <= n:
        s *= 4
        b += 1
    print(b)
