n = int(input())
for _ in range(n):
    g, k = map(int, input().split())
    if g <= 100:
        print(0)
        continue
    c = 100 * k - 90
    print((g - 100 + c - 1) // c)
