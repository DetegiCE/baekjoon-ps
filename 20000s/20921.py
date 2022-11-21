n, k = map(int,input().split())
c = 0
a = [n]
used = n
while (c * (c+1) // 2) < k:
    used -= 1
    if (c+2) * (c+1) // 2 <= k:
        a.append(used)
    else:
        a.insert(k-c*(c+1)//2, used)
        break
    c += 1
for i in range(1, used): print(i, end=' ')
for i in a: print(i, end=' ')
    