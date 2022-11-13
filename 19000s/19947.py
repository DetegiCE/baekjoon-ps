h, y = map(int,input().split())
a = [0 for i in range(11)]
a[0] = h
a[1] = int(a[0] * 1.05)
a[2] = int(a[1] * 1.05)
a[3] = max(int(a[2] * 1.05), int(h * 1.20))
a[4] = max(int(a[3] * 1.05), int(a[1] * 1.20))
for i in range(5, y+1):
    a[i] = max(int(a[i-5] * 1.35), int(a[i-3] * 1.20), int(a[i-1] * 1.05))
print(a[y])