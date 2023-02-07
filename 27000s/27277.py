n = int(input())
a = sorted(list(map(int, input().split())))
r = a[:n//2]
l = a[n//2:][::-1]
s = l[0]
for i in range(n//2):
    if n % 2 == 0 and i == n//2-1:
        break
    s += l[i+1] - r[i]
print(s)
