a = []
b = set()
for _ in range(36):
    c = input()
    a.append(c)
    b.add(c)
if len(b) != len(a):
    print('Invalid')
    quit()
a.append(a[0])
for i in range(36):
    d = abs(ord(a[i][0])-ord(a[i+1][0]))
    e = abs(ord(a[i][1])-ord(a[i+1][1]))
    if not((d == 1 and e == 2) or (d == 2 or e == 1)):
        print('Invalid')
        quit()
print('Valid')