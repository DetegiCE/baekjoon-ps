a = []
for _ in range(11):
    d, v = map(int, input().split())
    a.append([d, -v])
a.sort()
t = 0
s = 0
for i in a:
    d, v = i
    t += (s+d) - 20 * v
    s += d
print(t)
