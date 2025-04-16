x, c, k = map(int, input().split())
a = []
for _ in range(k):
    a.append(list(map(int, input().split())))
a.sort()

b = [0 for _ in range(c+1)]
stud = [0 for _ in range(x+1)]
for i in range(k):
    if b[a[i][1]] == 0:
        if stud[a[i][2]] == 0:
            b[a[i][1]] = a[i][2]
            stud[a[i][2]] = a[i][1]
        else:
            b[stud[a[i][2]]] = 0
            b[a[i][1]] = a[i][2]
            stud[a[i][2]] = a[i][1]
for i in range(1, x+1):
    if stud[i] != 0:
        print(i, stud[i])