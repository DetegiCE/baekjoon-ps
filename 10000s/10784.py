from math import *
p, a, b, c, d, n = map(int, input().split())
price = lambda k: p*(sin(a*k+b) + cos(c*k+d) + 2)
pr = []
for i in range(1, n+1):
    pr.append(price(i))
mx = 0
prmx = pr[0]
for i in range(1, n):
    if pr[i] > prmx:
        prmx = pr[i]
    else:
        mx = max(mx, prmx - pr[i])
print(mx)