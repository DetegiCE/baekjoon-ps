n = int(input())
c = 0
for _ in range(n):
    garo, sero = map(int, input().split())
    if garo == 136: c += 1000
    elif garo == 142: c += 5000
    elif garo == 148: c += 10000
    else: c += 50000
print(c)