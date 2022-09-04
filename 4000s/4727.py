while True:
    a,b,c,d=map(int,input().split())
    if a == b == c == d == 0:
        break
    mn = (max(b-0.5,0)) * 9 + (max(c-0.5,0)+max(d-0.5,0)) * 4
    mx = (b+0.5) * 9 + (c+d+1) * 4
    if mn <= a < mx:
        print('yes')
    else:
        print('no')