n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(len(a)-1):
    b.append(a[i+1] - a[i])
s = 0
mx = 0
for i in b:
    if s + i < 0:
        mx = max(mx, s)
        s = 0
    else:
        s += i
        mx = max(mx, s)
print(mx)
        