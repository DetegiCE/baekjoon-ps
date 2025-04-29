n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
s = sum(a)
for i in range(n//2):
    s += a[n-i-1] - a[i]
print(s)