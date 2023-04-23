for _ in range(int(input())):
    s = 1
    n = int(input())
    for i in range(1, n, 2):
        s *= i
        s %= 1000
    print(s)
