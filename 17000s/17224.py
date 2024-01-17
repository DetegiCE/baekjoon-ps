n, l, k = map(int, input().split())
e, h = 0, 0
for _ in range(n):
    a, b = map(int, input().split())
    if b <= l: h += 1
    elif a <= l: e += 1
s = min(h, k) * 140
if h < k:
    s += min(e, k-h) * 100
print(s)
