while True:
    a=input()
    if a=='0': break
    b=list(map(int,a.split()))
    p=1
    for i in range(1,b[0]*2+1):
        if i%2==1: p*=b[i]
        else: p-=b[i]
    print(p)