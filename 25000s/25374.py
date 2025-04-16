n = int(input())
a = list(map(int, input().split()))
a.sort()
a.reverse()

lim = a[3]
cnt = 0
for i in range(n):
    if a[i] >= lim: cnt += 1
print(cnt)
for i in range(n):
    if a[i] >= lim: a[i] = -1

for j in [10, 22, 39, 59, 76, 88, 95, 99]:
    if a[j] == -1:
        print(0)
    else:
        lim = a[j]
        cnt = 0
        for i in range(n):
            if a[i] >= lim: cnt += 1
        print(cnt)
        for i in range(n):
            if a[i] >= lim: a[i] = -1