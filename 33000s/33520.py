from sys import stdin
input = stdin.readline
n = int(input())
mx, my = -1, -1
for _ in range(n):
    a, b = map(int, input().split())
    mx = max(mx, min(a, b))
    my = max(my, max(a, b))
print(mx * my)
