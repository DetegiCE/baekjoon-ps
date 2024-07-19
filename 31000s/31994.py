a = []
for i in range(7):
    b, c = input().split()
    c = int(c)
    a.append([c, b])
a.sort()
print(a[-1][1])