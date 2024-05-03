n = int(input())
a = []
b = []
for i in range(1, int(n**0.5)+1):
    if n % i == 0 and i * (n//i) == n:
        a.append((i, n//i))
        a.append((n//i, i))
        a.append((-i, -n//i))
        a.append((-n//i, -i))
for i in range(1, int((n+2)**0.5)+1):
    if (n+2) % i == 0 and i * ((n+2)//i) == n+2:
        b.append((i, -(n+2)//i))
        b.append(((n+2)//i, -i))
        b.append((-i, (n+2)//i))
        b.append((-(n+2)//i, i))

flg = 0
for i in a:
    for j in b:
        if i[0] * j[1] + i[1] * j[0] == n+1:
            print(i[0], j[0], i[1], j[1])
            flg = 1
            break
    if flg == 1:
        break
if flg == 0:
    print(-1)
