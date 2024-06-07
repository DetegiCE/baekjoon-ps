n = int(input())
c = 0
d = 0
for _ in range(n):
    a = list(map(int, input().split())) + [0, 0]
    e = c
    for i in range(e, e+7):
        d += 1
        c += 1
        if a[i%7] == 1:
            break
print(d)
