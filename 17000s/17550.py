from sys import stdin
input = stdin.readline
n = int(input())
a = [0] + [int(input()) for _ in range(n)] + [0]
s = list(map(lambda x: x*x, a))

ac = [0 for _ in range(n+2)]
for i in range(n, -1, -1):
    ac[i] = ac[i+1] + a[i]
sc = [0]
for i in range(1, n+2):
    sc.append(sc[-1] + s[i])
    
m = 0
for i in range(n+1):
    m = max(m, sc[i] * ac[i+1])
print(m)