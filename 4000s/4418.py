case = 0
while True:
    a, b = map(int, input().split())
    if a == 0:
        break
    case += 1
    print(f'RFP #{case}')
    req = []
    for i in range(a):
        req.append(input().strip())
    pnt = []
    mxtp = -1
    for i in range(b):
        tp = 0
        n = input().strip()
        c, d = map(float, input().split())
        d = int(d)
        for j in range(d):
            if input().strip() in req:
                tp += 1
        pnt.append([n, c, tp])
        mxtp = max(mxtp, tp)
    prc = 1e30
    prn = ''
    for i in pnt:
        if i[2] == mxtp:
            if i[1] < prc:
                prc = i[1]
                prn = i[0]
    print(prn)
    print()
