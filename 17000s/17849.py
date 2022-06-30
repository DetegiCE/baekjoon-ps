n1,n2,n3=map(int,input().split())
c = [dict(), dict(), dict()]
for i in range(3):
    a=list(input().split())
    for j in range(0, len(a), 2):
        if a[j] in c[i]:
            c[i][a[j]] += int(a[j+1])
        else:
            c[i][a[j]] = int(a[j+1])
cnt = 0
ans = list()
for k, v in c[0].items():
    if c[0][k] >= 20 and k in c[1] and k in c[2] and c[1][k] >= 20 and c[2][k] >= 20:
        cnt += 1
        ans.append(str(k))
print(cnt, end=' ')
print(' '.join(ans))
