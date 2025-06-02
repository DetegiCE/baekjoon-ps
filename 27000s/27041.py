e, l, b = map(int, input().split())
a = [False] * (e+1)
for _ in range(b):
    b = int(input())
    a[b] = True
cur = 0
cnt = 0
while cur < e:
    if cur + l >= e:
        cnt += 1
        break
    
    npos = -1
    for i in range(cur + l, cur, -1):
        if i <= e and not a[i]:
            npos = i
            break
    
    cur = npos
    cnt += 1

print(cnt)