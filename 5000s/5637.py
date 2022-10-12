mxl = -1
mxw = ''
l = 0
w = ''
while True:
    a = input() + ' '
    endflg = 0
    for i in range(len(a)):
        if a[i-5:i] == 'E-N-D':
            endflg = 1
            break
        c = ord(a[i])
        if c == 45 or 65<=c<=90 or 97<=c<=122:
            l += 1
            w += a[i]
        else:
            if l > mxl:
                mxl = l
                mxw = w
            l = 0
            w = ''
    if endflg == 1:
        break
print(mxw.lower())