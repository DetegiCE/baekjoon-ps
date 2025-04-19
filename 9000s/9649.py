from math import gcd
while True:
    try:
        ab, ac, bd = map(int, input().split())
        up = ab * ac
        dn = bd - ac
        g = gcd(up, dn)
        print(f'{up//g}/{dn//g}')
    except:
        break