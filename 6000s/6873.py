a = []
while True:
    b = input()
    if b == 'SCHOOL': break
    a.append(b)
a.reverse()
for i in range(0, len(a), 2):
    if i == len(a)-1:
        print(f'Turn {"LEFT" if a[-1] == "R" else "RIGHT"} into your HOME.')
    else:
        if a[i] == 'L': print('Turn RIGHT onto', end=' ')
        else: print('Turn LEFT onto', end=' ')
        print(a[i+1], 'street.')