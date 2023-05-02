mod = 1000000007
n = int(input())
a = [0, 0, 1, 0, 3, 0]
for i in range(6, n+1):
    if i % 2 == 0:
        a.append((a[-2]*(i-1))%mod)
    else: a.append(0)
print(a[n])
