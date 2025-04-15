n = int(input())
sx, sy = 0, 0
sx2, sxy = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    sx += x
    sy += y
    sx2 += x * x
    sxy += x * y
if n*sx2-sx**2 == 0:
    print('EZPZ')
else:
    a = (n*sxy - sx*sy) / (n*sx2-sx**2)
    b = (sy-a*sx) / n
    print(a, b)