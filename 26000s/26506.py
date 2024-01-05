from sys import stdin
input = stdin.readline
n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort()
c = 1e9
for i in range(n//2):
    c = min(c, a[i] + a[n-i-1])
print(c)
