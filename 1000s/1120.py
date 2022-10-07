a, b = input().split()
alen = len(a)
blen = len(b)
mn = 51
for i in range(0, blen - alen + 1):
    c = 0
    for j in range(0, alen):
        if a[j] != b[i+j]:
            c += 1
    mn = min(c, mn)
print(mn)