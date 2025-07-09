from sys import stdin
from bisect import bisect_left as bl
input = stdin.readline
n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
a.sort()
for i in range(m):
    d = int(input())
    e = bl(a, d)
    if 0 <= e < n and a[e] == d: print(e)
    else: print(-1)