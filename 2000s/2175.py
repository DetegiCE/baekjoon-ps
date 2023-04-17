def mid(x1, y1, x2, y2):
    return (x1+x2)/2, (y1+y2)/2

def area3(x1, y1, x2, y2, x3, y3):
    return 0.5 * abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1)
    
def area4(x1, y1, x2, y2, x3, y3, x4, y4):
    return area3(x1, y1, x2, y2, x3, y3) + area3(x1, y1, x3, y3, x4, y4)

def f(mnb, mxb, s, cur):
    mnc = min(cur, s-cur)
    mxc = max(cur, s-cur)
    if mxb - mnb > mxc - mnc:
        return mnc, mxc
    else:
        return mnb, mxb

mna, mxa = -1e12, 1e12
ax, ay, bx, by, cx, cy, dx, dy = map(int, input().split())
s = area4(ax, ay, bx, by, cx, cy, dx, dy)
mna, mxa = f(mna, mxa, s, area3(ax, ay, bx, by, *mid(bx, by, cx, cy)))
mna, mxa = f(mna, mxa, s, area3(ax, ay, bx, by, cx, cy))
mna, mxa = f(mna, mxa, s, area3(ax, ay, *mid(cx, cy, dx, dy), dx, dy))

mna, mxa = f(mna, mxa, s, area3(ax, ay, *mid(ax, ay, bx, by), *mid(ax, ay, dx, dy)))
mna, mxa = f(mna, mxa, s, area3(ax, ay, bx, by, *mid(ax, ay, dx, dy)))
mna, mxa = f(mna, mxa, s, area4(ax, ay, bx, by, *mid(bx, by, cx, cy), *mid(ax, ay, dx, dy)))
mna, mxa = f(mna, mxa, s, area3(cx, cy, dx, dy, *mid(ax, ay, dx, dy)))
mna, mxa = f(mna, mxa, s, area3(*mid(cx, cy, dx, dy), dx, dy, *mid(ax, ay, dx, dy)))

mna, mxa = f(mna, mxa, s, area3(ax, ay, *mid(ax, ay, bx, by), dx, dy))
mna, mxa = f(mna, mxa, s, area3(ax, ay, bx, by, dx, dy))
mna, mxa = f(mna, mxa, s, area3(*mid(bx, by, cx, cy), cx, cy, dx, dy))

mna, mxa = f(mna, mxa, s, area4(ax, ay, *mid(ax, ay, bx, by), *mid(cx, cy, dx, dy), dx, dy))
mna, mxa = f(mna, mxa, s, area3(bx, by, cx, cy, *mid(cx, cy, dx, dy)))
mna, mxa = f(mna, mxa, s, area3(*mid(bx, by, cx, cy), cx, cy, *mid(cx, cy, dx, dy)))

mna, mxa = f(mna, mxa, s, area3(*mid(ax, ay, bx, by), bx, by, cx, cy))
mna, mxa = f(mna, mxa, s, area3(*mid(ax, ay, bx, by), bx, by, *mid(bx, by, cx, cy)))
print(mna, mxa)
