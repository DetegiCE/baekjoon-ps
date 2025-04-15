n = int(input())
v = [input() for _ in range(n)]
a = list(map(int, input().split()))
o = int(input())
c = 0
for i in range(n):
    b = o
    chk = True
    for j in range(len(v[i])):
        if v[i][0] != v[i][j]:
            chk = False
    if chk:
        match v[i][0]:
            case 'P': b = min(b, a[0])
            case 'C': b = min(b, a[1])
            case 'V': b = min(b, a[2])
            case 'S': b = min(b, a[3])
            case 'G': b = min(b, a[4])
            case 'F': b = min(b, a[5])
    c += len(v[i]) * b
print(c)