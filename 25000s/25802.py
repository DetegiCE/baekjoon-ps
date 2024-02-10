rep = []
for i in range(10):
    r = []
    for j in range(10):
        r.append(0)
    rep.append(r)
a, b = map(int, input().split())
cnt = 0
while True:
    if rep[a][b] == 1:
        break
    rep[a][b] = 1
    a, b = b, a + b
    a %= 10
    b %= 10
    cnt += 1
print(cnt+2)
