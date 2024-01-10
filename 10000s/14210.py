n = int(input())
a = []
for i in range(n):
    a.append(input())
b = input()
c = []
for i in range(n):
    if a[i].startswith(b):
        c.append(a[i][len(b)])
d = [list('***ABCDE'), list('FGHIJKLM'), list('NOPQRSTU'), list('VWXYZ***')]
for i in range(4):
    for j in range(8):
        if d[i][j] in c:
            print(d[i][j], end='')
        else:
            print('*', end='')
    print()
