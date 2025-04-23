n = int(input())
a = list(map(int, input().split()))
a.sort()
b = 0
for i in range(1-n%2, n):
    b += a[i] + a[i]%2 - 1
print(b)