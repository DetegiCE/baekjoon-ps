n = int(input())
a = []
for _ in range(n):
    a.append(input())
b = True
c = False
for i in range(n-1, -1, -1):
    if a[i] == 'TRUTH': c = True
    else: c = False
    if not b: c = not c
    b = c
if b: print('TRUTH')
else: print('LIE')