h,m,dh,dm,c=map(int,input().split())
a=h*60+m
b=dh*60+dm
a+=b
hh=(a//60)%12
mm=a%60
if c == 1:
    print(hh, mm)
else:
    if mm % 12 == 0:
        print('@', hh*5+mm//12)
    else:
        if hh*5+mm//12 == 59:
            print('59 0')
        else:
            print(hh*5+mm//12, hh*5+mm//12+1)