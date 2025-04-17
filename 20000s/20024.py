from math import comb
a, b, c = map(int, input().split())
lim = (c-1)//5+1
tot = comb(a, b)
if b-lim < 0: sos = 0
else: sos = comb(a-lim, b-lim)
print(1-sos/tot)