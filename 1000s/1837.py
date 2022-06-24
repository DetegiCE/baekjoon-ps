p,k=map(int,input().split())
pr=[False,False]+[True]*(k-2)
for i in range(2,int(k**0.5)+1):
    if pr[i]:
        for j in range(i*2,k,i):
            pr[j]=False
f=False
g=0
for i in range(2,k):
    if pr[i]:
        if p%i==0:
            f=True
            g=i
            break
print('GBOAODD'[f::2],['',g][f])