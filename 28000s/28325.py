n = int(input())
a = list(map(int, input().split()))
s = sum(a)
if s == 0:
    print(n//2)
    exit(0)
idx = 0
while idx < n:
    if a[idx] == 0:
        idx += 1
    else: break
a = a[idx:] + a[:idx]
b = [0]
for i in range(n):
    if a[i] == 0:
        b[-1] += 1
    else:
        b.append(0)
for i in b:
    s += (i+1)//2
print(s)