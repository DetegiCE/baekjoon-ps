t=int(input())
for _ in range(t):
    h,w=map(int,input().split())
    b=w/((h/100)**2)
    if h<140.1: print(6)
    elif h<146: print(5)
    elif h<159 or h>=204: print(4)
    elif h<161:
        if 16.0<=b<35: print(3)
        else: print(4)
    else:
        if 20.0<=b<25: print(1)
        elif 18.5<=b<30: print(2)
        elif 16<=b<35: print(3)
        else: print(4)