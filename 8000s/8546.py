a = [0, 1]
for i in range(10000002):
    a.append((a[-1]+a[-2])%10)
n, m = map(int, input().split())
for i in range(n, m+1):
    print(a[i], end='')