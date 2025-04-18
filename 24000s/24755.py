n = int(input())
a = sorted(list(map(int, input().split())))
b = 0
for i in range((n+1)//2):
    b += (a[i]-1)//2
for i in range((n+1)//2, n):
    b += a[i]
print(b)