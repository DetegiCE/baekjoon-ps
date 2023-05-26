n = int(input())
a, b = 1, 1
for _ in range(3, n+1):
    a, b = b, a+b
    b %= 1000000007
print(b, n-2)
