a,b=map(int,input().split())
c,d=map(int,input().split())
p=a/c+b/d
q=c/d+a/b
r=d/b+c/a
s=b/a+d/c
m=max(p,q,r,s)
if m==p: print(0)
elif m==q: print(1)
elif m==r: print(2)
else: print(3)