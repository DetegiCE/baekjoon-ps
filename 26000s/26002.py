from math import gcd as g
l, w, n = map(int, input().split())
gl = l // g(l, n)
gw = (l*w) // n // gl
if (l*w) % n != 0:
    print('impossible')
    exit()
if ((l*w) // n) % gl != 0:
    print('impossible')
    exit()
if gw > w:
    print('impossible')
    exit()
for i in range(l):
    for j in range(w):
        t = (i//gl)*(w//gw) + (j//gw)
        print(chr(65+t), end='')
    print()
