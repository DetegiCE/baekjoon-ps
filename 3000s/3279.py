n = int(input())
s = 100
a = []
for i in range(n):
    a.append(int(input()))
for i in range(n-1):
    if a[i] > a[i+1]:
        s *= a[i] / a[i+1]
print("%.2f" % s)
