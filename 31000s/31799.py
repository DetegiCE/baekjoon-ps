input()
a = input()
if a[-1] in 'ABC': a = a + '0'
i = 0
b = []
while i < len(a)-1:
    if a[i] in 'ABC' and a[i+1] in 'ABC':
        b.append(a[i]+'0')
        i += 1
    else:
        b.append(a[i:i+2])
        i += 2
c = []
match b[0]:
    case 'A+' | 'A0':
        c.append('E')
    case 'A-' | 'B+':
        c.append('P')
    case 'B0' | 'B-':
        c.append('D')
    case _:
        c.append('B')
for i in range(1, len(b)):
    if b[i] == 'A+':
        c.append('E')
    elif b[i] == 'A0':
        if b[i-1] in ['A+', 'A0']: c.append('P')
        else: c.append('E')
    elif b[i] in ('A-', 'B+'):
        if b[i-1].startswith('A') or b[i-1] == 'B+': c.append('D')
        else: c.append('P')
    elif b[i] in ('B0', 'B-'):
        if b[i-1].startswith('C'): c.append('D')
        else: c.append('B')
    else:
        c.append('B')
print(''.join(c))