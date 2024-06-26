h, w, n = map(int, input().split())
ha = [1]
wa = [1]
for i in range(2, (h+1)//2+1):
    ha.append(i)
for i in range(2, (w+1)//2+1):
    wa.append(i)
ch, cw = -1, -1
for i in ha:
    for j in wa:
        if i * j == n:
            ch = i
            cw = j
            break
    if ch != -1:
        break

if ch == -1 and cw == -1:
    print('Impossible')
    exit(0)

ch -= 1
cw -= 1
mp = []
for i in range(h):
    mp.append(list('.'*w))
for i in range(1, ch*2, 2):
    for j in range(w):
        mp[i][j] = '#'
for j in range(1, cw*2, 2):
    for i in range(h):
        mp[i][j] = '#'
for i in range(h):
    print(''.join(mp[i]))