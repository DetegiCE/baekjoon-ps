from math import acos, cos, tan
for _ in range(int(input())):
    v0, t, x1, h1, h2 = map(float, input().split())
    t = (t / 180) * acos(-1)
    t1 = x1 / (v0 * cos(t))
    y = x1 * tan(t) - ((9.81 * x1 * x1) / (2 * v0 * v0 * cos(t) * cos(t)))
    if h1 + 1 < y < h2 - 1:
        print('Safe')
    else: print('Not Safe')