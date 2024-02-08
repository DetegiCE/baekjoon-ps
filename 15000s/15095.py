a = []
c = 0
for i in range(5):
    a.append(input())
for i in range(5):
    for j in range(5):
        if a[i][j] == 'k':
            c += 1
if c != 9:
    print('invalid')
    exit()
dx=[1,2,2,1,-1,-2,-2,-1]
dy=[-2,-1,1,2,2,1,-1,-2]
flg = 0
for i in range(5):
    for j in range(5):
        if a[i][j] == 'k':
            for k in range(8):
                ni = i+dx[k]
                nj = j+dy[k]
                if 0 <= ni < 5 and 0 <= nj < 5 and a[ni][nj] == 'k':
                    flg = 1
                    break
if flg == 1:
    print('invalid')
else: print('valid')
