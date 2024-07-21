n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    if a[i] == i+1:
        cnt += 1
print(cnt)
for i in range(n):
    if a[i] == i+1:
        if i == n-1: print(1, end=' ')
        else: print(i+2, end=' ')
    else:
        print(a[i], end=' ')