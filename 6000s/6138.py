t, n = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort(key = lambda x: abs(x))

t -= abs(a[0])
for i in range(1, n):
    dif = abs(a[i] - a[i-1])
    if t < dif:
        print(i)
        exit(0)
    t -= dif
print(n)