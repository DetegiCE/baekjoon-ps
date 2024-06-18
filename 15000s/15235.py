n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n):
    b.append(0)
q = []
for i in range(n):
    q.append([i, a[i]])
t = 0
while q:
    t += 1
    if q[0][1] == 1:
        b[q[0][0]] = t
    else:
        q.append([q[0][0], q[0][1]-1])
    q.pop(0)
for i in b:
    print(i, end=' ')
