from math import gcd
a,b=map(int,input().split())
g = gcd(a,b)
div = [1, g]
for i in range(2, int(g**0.5)+1):
    if i * i == g:
        div.append(i)
        break
    if g % i == 0:
        div.append(i)
        div.append(g//i)
div.sort()
for i in div:
    print(i, a//i, b//i)