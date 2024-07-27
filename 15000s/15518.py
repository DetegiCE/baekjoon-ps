n, h, w = map(int, input().split())
a = list(map(int, input().split()))
c = [False] * (n * w)
for i in range(n):
    if i % 2 == 0:
        st = w * i + a[i]
        en = w * (i+1) + a[i]
    else:
        st = w * i - a[i]
        en = w * (i+1) - a[i]
    
    st = max(st, 0)
    en = min(en, n * w)

    for j in range(st, en):
        if 0 <= j < n * w:
            c[j] = True

print(c.count(False) * h)