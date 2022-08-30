l,g,r=map(int,input().split())
p=dict()
q=dict()
for i in range(g):
    n,a,d=input().split()
    a=int(a)
    d=int(d)
    p[n] = a
    q[n] = d
b=[0 for i in range(l+1)]
for i in range(r):
    o=input()
    a=p[o]
    d=q[o]
    for j in range(a,l+1,d):
        b[j] = 1-b[j]
c=0
for i in range(1, l+1):
    if b[i] == 1:
        c += 1
print(c)