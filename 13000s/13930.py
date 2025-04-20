x, y = map(int, input().split())
n = int(input())
if n == 0:
    print(x/y)
    exit(0)
s = sorted([list(map(float, input().split())) for _ in range(n)])
t = 0
for i in range(n):
    t += s[i][2] * (s[i][1] - s[i][0])
for i in range(n-1):
    t += s[i+1][0] - s[i][1]
t += s[0][0]
t += y - s[n-1][1]
print(x/t)