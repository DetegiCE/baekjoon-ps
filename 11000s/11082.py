from math import gcd
a = input()
if '.' not in a:
    print(f'{a}/1')
    exit(0)
if '(' not in a:
    b, c = a.split('.')
    up = int(b+c)
    dn = 10 ** len(c)
    g = gcd(up, dn)
    print(f'{up//g}/{dn//g}')
    exit(0)
b, c = a.split('.')
d, e = c.split('(')
e = e[:-1]
up = int(b+c.replace('(','').replace(')','')) - int(b+d)
dn = int('9' * len(e) + '0' * len(d))
g = gcd(up, dn)
print(f'{up//g}/{dn//g}')
