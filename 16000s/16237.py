a,b,c,d,e=map(int,input().split())
gabang = [0] * 5001
for i in range(5001):
    if e == 0:
        break
    if gabang[i] == 0:
        gabang[i] = 5
        e -= 1
for i in range(5001):
    if d == 0:
        break
    if gabang[i] == 0 or gabang[i] == 1:
        gabang[i] += 4
        d -= 1
for i in range(5001):
    if c == 0:
        break
    if gabang[i] <= 2:
        gabang[i] += 3
        c -= 1
for i in range(5001):
    if b == 0:
        break
    if 5 - gabang[i] >= 2:
        gabang[i] += 2
        b -= 1
    if b == 0:
        break
    if 5 - gabang[i] >= 2:
        gabang[i] += 2
        b -= 1
for i in range(5001):
    for j in range(5):
        if a == 0:
            break
        if 5 - gabang[i] >= 1:
            gabang[i] += 1
            a -= 1
    if a == 0:
        break
cnt = 0
for i in range(5001):
    if gabang[i] > 0:
        cnt += 1
    else:
        break
# print(gabang[:20])
print(cnt)