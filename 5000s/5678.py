n = -1

def sol():
    m = list(map(int,input().split()))
    l = list(map(int,input().split()))
    sm = sum(m)
    sl = sum(l)
    ism = isl = False
    for i in range(n-2):
        if m[i] == m[i+1] == m[i+2]:
            ism = True
            if l[i] == l[i+1] == l[i+2]:
                isl = True
                break
            break
        elif l[i] == l[i+1] == l[i+2]:
            isl = True
            break
    if ism and not isl:
        sm += 30
    if isl and not ism:
        sl += 30
    if sm > sl: print('M')
    elif sm < sl: print('L')
    else: print('T')

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        sol()