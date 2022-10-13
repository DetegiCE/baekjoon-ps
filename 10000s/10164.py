from math import comb
a,b,c=map(int,input().split())
if c == 0:
    print(comb(a+b-2,b-1))
else:
    c-=1
    cg,cs=c%b,c//b
    print(comb(cg+cs,cs)*comb((b-cg-1)+(a-cs-1),a-cs-1))