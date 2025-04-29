a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i in range(3):
    for j in range(7):
        c.append((a[i]/b[j], i, j))
c.sort()
for i in c:
    print(f'{i[0]:.2f} {i[1]+1} {i[2]+1}')