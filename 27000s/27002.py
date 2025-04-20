mp = [2, 3, 5, 7]
for i in range(11, 20000, 2):
    f = 0
    for j in mp:
        if j * j > i: break
        if i % j == 0:
            f = 1
            break
    if f == 0:
        mp.append(i)
n = int(input())
mx = 1
mxi = 1
for i in range(n):
    a = int(input())
    for j in mp:
        if a % j == 0:
            if j > mx:
                mx = j
                mxi = a
print(mxi)