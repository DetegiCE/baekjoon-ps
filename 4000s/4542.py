for _ in range(int(input())):
    n = int(input())
    a = []
    for i in range(n):
        a.append(input())
    flg2 = 0
    for l in range(60, 2, -1):
        flg = 0
        mst = []
        for j in range(0, 61-l):
            cnt = 1
            p = a[0][j:j+l]
            for k in range(1, n):
                if p in a[k]: cnt+=1
                else: break
            if cnt == n:
                mst.append(p)
                flg = 1
        if flg == 1:
            mst.sort()
            print(mst[0])
            flg2 = 1
            break
    if flg2 == 0:
        print('no significant commonalities')