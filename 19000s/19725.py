from itertools import combinations

n = int(input())
a = input()
m = int(input())
b = [input() for _ in range(m)]
c = []

for i, j in combinations(range(m), 2):
    oi, oj = 0, 0
    xi, xj = 0, 0

    for k in range(n):
        is_oi = b[i][k] == a[k]
        is_oj = b[j][k] == a[k]

        if is_oi and is_oj:
            oi += 1
        elif not is_oi and not is_oj:
            if b[i][k] == b[j][k]:
                xi += 1

    toi = sum(b[i][k] == a[k] for k in range(n))
    toj = sum(b[j][k] == a[k] for k in range(n))
    txi = n - toi
    txj = n - toj

    if (oi > toi / 2 and oi > toj / 2 and
        xi > txi / 2 and xi > txj / 2):
        c.append((i + 1, j + 1))

print(len(c))
for i in c:
    print(*i)
