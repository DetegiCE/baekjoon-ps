while True:
    a,b,c=map(float,input().split())
    if a == b == c == 0:
        break
    d=[a,b,c]
    d.sort()
    a=d[2]
    b=d[1]
    c=d[0]
    if 125 <= a <= 290 and 90 <= b <= 155 and 0.25 <= c <= 7:
        print('letter')
    elif 125 <= a <= 380 and 90 <= b <= 300 and 0.25 <= c <= 50 and (a > 290 or b > 155 or c > 7):
        print('packet')
    elif 125 <= a and 90 <= b and 0.25 <= c and (a > 380 or b > 300 or c > 50) and a+(b+c)*2 <= 2100:
        print('parcel')
    else:
        print('not mailable')