a, b = input().split()
b = int(b)
e = len(a.split('.')[1])
c = int(a.replace('.',''))
d = str(c**b)
if len(d) > e * b:
    print(d[:-(e*b)]+'.'+d[-(e*b):].rstrip('0'))
else:
    print('0.'+d.zfill(e*b))
