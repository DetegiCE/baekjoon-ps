b, r = map(int, input().split())
a = [0 for _ in range(b+1)]

for _ in range(r):
    h, v, c = map(int, input().split())
    mx = 0
    for i in range(c, c+h):
        mx = max(mx, a[i])
    for i in range(c, c+h):
        a[i] = mx + v
print(max(a[1:b+1]))