n = int(input())
a = list(map(int, input().split()))
b = 1
c = []
for i in range(1, n):
    if a[i-1] == a[i]:
        b += 1
    else:
        c.append(b)
        b = 1
c.append(b)

mx = c[0]
for i in range(1, len(c)):
    mx = max(mx, c[i-1] + c[i])
print(mx)