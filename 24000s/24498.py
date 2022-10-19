n = int(input())
a = list(map(int,input().split()))
mx = 0
for i in range(1, n-1):
    mx = max(mx, a[i] + min(a[i-1], a[i+1]))
mx = max(mx, a[0], a[n-1])
print(mx)