from math import gcd as g
input();a=list(map(int,input().split()))
input();b=list(map(int,input().split()))
c,d=1,1
for i in a:
    c *= i
for i in b:
    d *= i
e = str(g(c,d))
if len(e) > 9: print(e[-9:])
else: print(e)
