t = int(input())
a = []
for _ in range(t):
    a.append(list(map(int, input().split())))
a.sort()
s = 0
for i in a:
    if i[0] >= s:
        s = i[0]
    s += i[1]
print(s)