k, n = map(int, input().split())
a = list(map(int, input().split()))
b = []
for i in range(k):
    if a[i] == 1:
        b.append(i)
if len(b) < n:
    print(-1)
else:
    mn = 9999999
    lb = len(b)
    for i in range(lb - n + 1):
        mn = min(mn, b[i+n-1]-b[i]+1)
    print(mn)