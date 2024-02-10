def point(a):
    g = a.split('.')[0]
    f = a.split('.')[1]
    if int(f[2]) >= 5:
        return '{:.2f}'.format(float(g + '.' + f[:2]) + 0.01)
    else:
        return '{:.2f}'.format(float(g + '.' + f[:2]))
    
    
a = input().replace(' ', '')
ph = 0
pg = 0
for i in a:
    if i in 'HAPY':
        ph += 1
    if i in 'SAD':
        pg += 1
if ph == 0 and pg == 0:
    print('50.00')
else:
    print(point('{:.4f}'.format((ph*100)/(ph+pg))))
