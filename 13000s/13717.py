n = int(input())
b = []
for _ in range(n):
    a = input()
    k, m = map(int, input().split())
    c = 0
    while m >= k:
        m -= k
        m += 2
        c += 1
    b.append([-c, a])
s = 0
m = 0
for i in b:
    s -= i[0]
    m = min(m, i[0])
print(s)
for i in b:
    if i[0] == m:
        print(i[1])
        break
