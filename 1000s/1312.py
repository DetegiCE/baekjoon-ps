a, b, n = map(int, input().split())
a %= b
for i in range(n):
    a *= 10
    if i == n-1:
        print(a//b)
        break
    a %= b