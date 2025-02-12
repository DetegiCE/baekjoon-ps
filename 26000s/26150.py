n = int(input())
a = []
for _ in range(n):
    b, c, d = input().split()
    c, d = int(c), int(d)
    a.append([b, c, d])
a.sort(key=lambda x: x[1])
e = ''
for i in a:
    e += i[0][i[2]-1].upper()
print(e)