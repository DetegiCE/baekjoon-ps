l,h,p,e,n=map(int,input().split())
la=lb=ha=hb=pa=pb=ea=eb=0
for i in range(n):
    s = input().split(': ')
    if s[0][0] == 'L':
        la += int(s[1].split('/')[0])
        lb += int(s[1].split('/')[1])
    if s[0][0] == 'H':
        ha += int(s[1].split('/')[0])
        hb += int(s[1].split('/')[1])
    if s[0][0] == 'P':
        pa += int(s[1].split('/')[0])
        pb += int(s[1].split('/')[1])
    if s[0][0] == 'E':
        ea += int(s[1].split('/')[0])
        eb += int(s[1].split('/')[1])
sums = l*la/lb + h*ha/hb + p*pa/pb + e*ea/eb
sums /= (l+h+p+e)
sums *= 100
print(int(sums))