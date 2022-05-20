n = int(input())
g = list()
for i in range(6):
    a, b = map(int, input().split())
    g.append(b)
me = max(g[0::2])
mo = max(g[1::2])
tot = me * mo
sm = 0
if g[0] == me and g[1] == mo: sm = g[3] * g[4]
if g[1] == mo and g[2] == me: sm = g[4] * g[5]
if g[2] == me and g[3] == mo: sm = g[5] * g[0]
if g[3] == mo and g[4] == me: sm = g[0] * g[1]
if g[4] == me and g[5] == mo: sm = g[1] * g[2]
if g[5] == mo and g[0] == me: sm = g[2] * g[3]
print((tot-sm)*n)