n, s, r = map(int, input().split())
k = []
for i in range(n+2):
    k.append(1)
a = list(map(int, input().split()))
for i in a:
    k[i] = 0
b = list(map(int, input().split()))
for i in range(r):
    if k[b[i]] == 0:
        k[b[i]] = 1
        b[i] = -1
for i in range(r):
    if b[i] == -1:
        continue
    if k[b[i]-1] == 0:
        k[b[i]-1] = 1
        b[i] = -1
        continue
    if k[b[i]+1] == 0:
        k[b[i]+1] = 1
        b[i] = -1
        continue
c = 0
for i in range(1, n+1):
    if k[i] == 0:
        c += 1
print(c)
