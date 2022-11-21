a=input()+'  '
i=0
d=dict(zip('RBL','SKH'))
while i < len(a)-2:
    b = a[i:i+3]
    if 'R' in b and 'B' in b and 'L' in b:
        print('C', end='')
        i+=2
    else:
        print(d[a[i]], end='')
    i+=1