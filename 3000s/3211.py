n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()
mx = 1
for i in range(n):
    if a[i] >= i+1:
        mx = i+2
    else:
        break
print(mx)
