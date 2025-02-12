n = int(input())
a = list(map(int, input().split()))
b = [0, 0]
for i in range(2, n):
    if a[i-2] <= a[i-1] <= a[i] or a[i-2] >= a[i-1] >= a[i]:
        b.append(0)
    elif b[i-1] == 0: b.append(1)
    else: b.append(b[i-1] + 1)
print(max(b)+2)