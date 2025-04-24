n = int(input())
a = [list(map(int, input().split()))[1:] for _ in range(n)]
m = 0
for i in a:
    m = max(m, max(i))
c = 0
for i in a:
    c += (m - max(i)) * len(i)
print(c)