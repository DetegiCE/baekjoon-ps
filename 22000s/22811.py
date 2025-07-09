while True:
    n = int(input())
    if n == 0: break
    w, h = map(int, input().split())
    x, y = [], []
    for _ in range(n):
        xx, yy = map(int, input().split())
        x.append(xx)
        y.append(yy)
    s, t = map(int, input().split())
    mx = 0
    for stx in range(1, w-s+2):
        for sty in range(1, h-t+2):
            cnt = 0
            for i in range(n):
                if stx <= x[i] < stx+s and sty <= y[i] < sty+t:
                    cnt += 1
            mx = max(cnt, mx)
    print(mx)