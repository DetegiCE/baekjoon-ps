n = int(input())
am, af = map(int, input().split())
bm, bf = map(int, input().split())
cm, cf = map(int, input().split())
for ab in range(min(am, bf)+1):
    ac = am - ab
    for ba in range(min(bm, af)+1):
        bc = bm - ba
        ca = af - ba
        cb = cm - ca
        if ab + ac == am and ba + ca == af and ba + bc == bm and \
            ab + cb == bf and ca + cb == cm and ac + bc == cf and \
            ac >= 0 and bc >= 0 and ca >= 0 and cb >= 0:
            print(1)
            print(ab, ac)
            print(ba, bc)
            print(ca, cb)
            exit(0)
print(0)
        
    
