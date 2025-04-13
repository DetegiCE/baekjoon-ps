n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
    c = 0
    for j in range(0, i):
        if a[i] > a[j]: c += 1
    print(c)