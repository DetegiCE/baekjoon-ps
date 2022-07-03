a=list(map(int,input().split()))
b=[]

def append_list(i,j,k,l,m):
    num = a[i]*10000+a[j]*1000+a[k]*100+a[l]*10+a[m]
    if num < 10000:
        return
    if num in b:
        return
    b.append(num)

for i in range(5):
    for j in range(5):
        for k in range(5):
            for l in range(5):
                for m in range(5):
                    if i != j and j != k and k != l and l != m and m != i:
                        append_list(i,j,k,l,m)
cnt = 0
print(b, len(b))
for i in range(len(b)):
    for j in range(len(b)):
        for k in range(len(b)):
            for l in range(len(b)):
                if i!=j and j!=k and k!=l and l!=i and b[i]+b[j]+b[k]==b[l]:
                    cnt += 1
print(cnt)