n = int(input())
a = input().split()
d = {}
for i in a:
    d[i] = 0
for i in range(n):
    b = input().split()
    for j in b:
        d[j] += 1
c = sorted(d.items(), key=lambda x:(-x[1], x[0]))
for i in c:
    print(i[0], i[1])
