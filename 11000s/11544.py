n, m = map(int, input().split())
v = [10000, 1000, 100, 10, 1]
ans = 0
for i in range(m):
    a = list(map(int, input().split()))
    b, f, s = a[0], a[1], sum(a[1:])
    if s <= b:
        for j in v:
            if s - f + j <= b:
                ans += j - f
                break
    else:
        for j in v:
            if s - f + j <= b:
                ans += j
                break
print(ans)