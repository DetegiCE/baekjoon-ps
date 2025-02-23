n = int(input())
w = dict()
for i in range(n):
    for j in range(4):
        a = input().split()
        for k in range(7):
            if a[k] != '-':
                if a[k] in w:
                    w[a[k]] += [4,6,4,10][j]
                else:
                    w[a[k]] = [4,6,4,10][j]

mn = 1e18
mx = 0
for i in w:
    mn = min(mn, w[i])
    mx = max(mx, w[i])

if not w:
    mn = 0
if mx - mn > 12: print('No')
else: print('Yes')