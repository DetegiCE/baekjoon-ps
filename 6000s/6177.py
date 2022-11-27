n=int(input())
a=[]
for _ in range(n):
    a.append(int(input()))
a.sort()
print(sum(a)/len(a))
if n % 2 == 1:
    print(a[n//2])
else:
    print((a[n//2-1]+a[n//2])/2)