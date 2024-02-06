a = list(input())
b = sorted(a[:3])
c = sorted(a[3:], reverse=True)
for i in range(3):
    print(b[i]+c[i], end='')
