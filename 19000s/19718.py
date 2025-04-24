a = [int(input()) for _ in range(3)]
a.sort()
print(a[2] - a[1] + (a[1] - a[0]) * 2)