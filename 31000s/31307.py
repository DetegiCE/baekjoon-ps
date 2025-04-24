n, lph = map(int, input().split())
loc = [int(input()) for _ in range(n)]
loc.sort()

a = 0
pos = 0
for i in range(n):
    if pos + loc[i] > lph * 5:
        break
    pos += loc[i]
    a += 1
print(a)