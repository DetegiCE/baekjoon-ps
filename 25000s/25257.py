d, s, e = map(int, input().split())
sel = max(0.0, 2*s+e-d)
p = sel / d
d -= sel
s -= sel
p1 = s/d
p2 = s/(d-s-e)
print("%.10f" % (p+(1-p)*(1-p1)*p2))

