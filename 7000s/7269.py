n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
last = (sum(a[:-1]) - a[-1]) // (n-2)
for i in range(n-1):
    print(a[i]-last)
print(last)
