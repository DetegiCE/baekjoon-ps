n = int(input())
a = list(map(int, input().split()))
a.append(a[-1])

b = n
for i in range(n):
    if a[i] != a[i+1]:
        b += 1
    for j in range(i+2, n):
        c = 0
        for k in range(i+1, j):
            if a[k] > a[k-1] and a[k] > a[k+1]: c += 1
            elif a[k] < a[k-1] and a[k] < a[k+1]: c += 1
        if c == j-i-1:
            b += 1
        else: break
print(b)