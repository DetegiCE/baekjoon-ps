n, d = map(int, input().split())
s = 0
d = str(d)
for i in range(1, n+1):
    s += str(i).count(d)
print(s)