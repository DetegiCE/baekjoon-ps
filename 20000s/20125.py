n = int(input())
a = []
for i in range(n):
    a.append(input())
cr = 0
cc = 0
for i in range(1, n-1):
    for j in range(1, n-1):
        if a[i][j] == '*' and a[i-1][j] == '*' and a[i][j-1] == '*' and \
            a[i+1][j] == '*' and a[i][j+1] == '*':
            cr = i
            cc = j
            print(cr+1, cc+1)
            break
    if cr != 0:
        break
cnt = 0
for i in range(cc-1, -1, -1):
    if a[cr][i] == '*': cnt += 1
    else: break
print(cnt, end=' ')
cnt = 0
for i in range(cc+1, n):
    if a[cr][i] == '*': cnt += 1
    else: break
print(cnt, end=' ')
cnt = 0
sr = 0
for i in range(cr+1, n):
    if a[i][cc] == '*': cnt += 1
    else: 
        sr = i
        break
print(cnt, end=' ')
cnt = 0
for i in range(sr, n):
    if a[i][cc-1] == '*': cnt += 1
    else: break
print(cnt, end=' ')
cnt = 0
for i in range(sr, n):
    if a[i][cc+1] == '*': cnt += 1
    else: break
print(cnt, end=' ')