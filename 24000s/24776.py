d = dict()
while True:
    s = input()
    if s == '***': break
    if s in d: d[s] += 1
    else: d[s] = 1
a = list(d.items())
a.sort(key=lambda x: -x[1])
if a[0][1] == a[1][1]: print('Runoff!')
else: print(a[0][0])