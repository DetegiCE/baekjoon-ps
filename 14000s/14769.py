n = int(input())
c = []
for i in range(n):
    a, b = input().split()
    if a[0] in '1234567890':
        c.append((int(a), b))
    else:
        c.append((int(b)*2, a))
c.sort()
for i in c:
    print(i[1])