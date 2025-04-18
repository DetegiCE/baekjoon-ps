n, k = map(int, input().split())
a = list(map(int, input().split()))
b = [1]
for i in range(1, n):
    if a[i-1] != a[i]:
        b.append(b[-1]+1)
    else:
        b.append(1)
print(max(b))