n = int(input())
d = {}
for i in range(n):
    for j in range(4):
        a = input().split()
        if j == 0:
            for k in a:
                if k in d: d[k] += 4
                else: d[k] = 4
        if j == 1:
            for k in a:
                if k in d: d[k] += 6
                else: d[k] = 6
        if j == 2:
            for k in a:
                if k in d: d[k] += 4
                else: d[k] = 4
        if j == 3:
            for k in a:
                if k in d: d[k] += 10
                else: d[k] = 10
if '-' in d:
    del d['-']
if len(d) == 0:
    print('Yes')
    exit()
l = list(d.values())
if max(l) - min(l) <= 12: print('Yes')
else: print('No')
