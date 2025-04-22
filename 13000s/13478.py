def chk(a, b, c, d):
    if a < c: return -1
    if b < d: return -1
    e = 0
    while a > c:
        e += 1
        a = (a+1)//2
    while b > d:
        e += 1
        b = (b+1)//2
    return e

w, h = map(int, input().split())
r, c = map(int, input().split())
if w > h: w, h = h, w
if r > c: r, c = c, r

if w < r or h < c:
    print(-1)
    exit(0)
a = chk(w, h, r, c)
b = chk(w, h, c, r)
if a == -1: print(b)
elif b == -1: print(a)
else: print(min(a, b))