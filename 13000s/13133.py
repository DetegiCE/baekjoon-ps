n = int(input())
a = [False] + [True] * n
b = [[0,0]] + [list(map(int, input().split())) for _ in range(n)]
m = int(input())
for i in list(map(int, input().split())):
    a[i] = False
c = 0
for i in range(1, n+1):
    if a[i] and a[b[i][0]] and a[b[i][1]]:
        c += 1
print(c)