n = int(input())
a = sorted(list(map(int, input().split())))
c = 0
for i in range(1, n):
    if a[i-1] == a[i]: c += 1
print(c)
