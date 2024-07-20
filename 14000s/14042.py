a = int(input())
n = int(input())
d = list(map(int, input().split()))
p = list(map(int, input().split()))
d.sort()
p.sort()
if a == 2:
    p = p[::-1]
s = 0
for i in range(n):
    s += max(d[i], p[i])
print(s)