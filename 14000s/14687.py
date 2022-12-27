n=int(input())
a=list(map(int,input().split()))
a.sort()
d=n//2
if n % 2 == 1:
    d += 1
s=a[:d][::-1]
m=a[d:]
for i in range(n//2):
    print(s[i], m[i], end=' ')
if n % 2 == 1:
    print(s[-1])
