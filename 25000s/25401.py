n=int(input())
a=list(map(int,input().split()))
mn = 501
for i in range(n):
    for j in range(i+1, n):
        if (a[j]-a[i]) % (j-i) != 0:
            continue
        cnt = 0
        dif = (a[j]-a[i]) // (j-i)
        st = a[i] - dif * (i)
        for k in range(n):
            if a[k] != st + dif * k:
                cnt+=1
        mn = min(mn, cnt)
print(mn)
        