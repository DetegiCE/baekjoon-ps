while True:
    n = int(input())
    if n == 0: break
    c = 50
    d = 0
    mn, mx = -1, -1
    while True:
        d += 1
        if c == n:
            break
        if n % 2 != c % 2:
            if c % 2 == 0: c -= 1
            else: c += 1
            continue
        if n < c:
            if mn == -1:
                mn = [2, 1][n % 2]
                mx = c-2
                cnt = (mx+2-mn)//2
                if cnt % 2 == 1:
                    c = mn+cnt//2*2
                else:
                    c = mn+(cnt-1)//2*2
            else:
                mx = c-2
                cnt = (mx+2-mn)//2
                if cnt % 2 == 1:
                    c = mn+cnt//2*2
                else:
                    c = mn+(cnt-1)//2*2
        else:
            if mn == -1:
                mn = c + 2
                mx = [100, 99][n % 2]
                cnt = (mx+2-mn)//2
                if cnt % 2 == 1:
                    c = mn+cnt//2*2
                else:
                    c = mn+(cnt-1)//2*2
            else:
                mn = c + 2
                cnt = (mx+2-mn)//2
                if cnt % 2 == 1:
                    c = mn+cnt//2*2
                else:
                    c = mn+(cnt-1)//2*2
    print(d)