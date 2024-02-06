l, r, b, k = map(int, input().split())
a = l // b * b
if a < l:
    a += b
print(k * a)
