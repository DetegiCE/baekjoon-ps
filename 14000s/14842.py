w, h, n = map(int, input().split())
if n % 2 == 0:
    print(2 * h * ((n-2)/4))
else:
    print(2 * h * (n-1) ** 2 / (n * 4))