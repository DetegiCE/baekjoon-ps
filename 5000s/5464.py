n = m = -1
rs = []
wk = []
q = []
parknum = []
wait = []
s = 0

if __name__ == '__main__':
    n, m = map(int,input().split())
    parknum = [-1 for _ in range(m+1)]
    wk.append(0)
    rs.append(0)
    for _ in range(n):
        rs.append(int(input()))
        q.append(_ + 1)
    for _ in range(m):
        wk.append(int(input()))
    for _ in range(2*m):
        a = int(input())
        if a > 0:
            if len(q) == 0:
                wait.append(a)
                continue
            mq = min(q)
            parknum[a] = mq
            q.remove(mq)
        else:
            s += rs[parknum[(-a)]] * wk[(-a)]
            q.append(parknum[(-a)])
            if len(wait) > 0:
                parknum[wait[0]] = parknum[-a]
                q.remove(parknum[(-a)])
                wait.pop(0)
    print(s)