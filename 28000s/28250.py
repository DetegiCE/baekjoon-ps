n = int(input())
a = list(map(int, input().split()))
c0 = 0
c1 = 0
c2 = 0
for i in a:
    if i == 0: c0 += 1
    elif i == 1: c1 += 1
    else: c2 += 1
r1 = c0 * (c0 - 1) // 2 + c0 * c2
r2 = c0 * c1
print(r1 + r2 * 2)