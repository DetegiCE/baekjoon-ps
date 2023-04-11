from sys import stdin
input = stdin.readline
n, m, k = map(int, input().rstrip().split())
for i in range(m):
    t, r = map(int, input().rstrip().split())
    k -= r
    if k < 0:
        print(i+1, 1)
        exit(0)
print(-1)
