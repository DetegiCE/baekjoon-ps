n = int(input())
a = list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
m = []
for i in range(n+1):
    m.append(0)
for i in range(n):
    m[a[i]] = i+1
c = []
for i in range(n+1):
    c.append(0)
for i in range(1, n+1):
    cur = i
    for j in range(3):
        cur = m[cur]
    c[cur] = b[i]
for i in range(1, n+1):
    print(c[i])
