n = int(input())
a = [input() for _ in range(n)]
m = int(input())
b = [input() for _ in range(m)]
chk = [False for _ in range(n)]
c = 0
for i in range(m):
    for j in range(n):
        if chk[j]: continue
        if b[i] == a[j]:
            chk[j] = True
            c += 1
            if c >= n/2:
                print(i+1)
                exit(0)