n, m = map(int, input().split())
garo = [0] * n
sero = [0] * m
for i in range(n):
    a = input()
    for j in range(m):
        if a[j] == 'X':
            garo[i] = 1
            sero[j] = 1
print(max(garo.count(0), sero.count(0)))