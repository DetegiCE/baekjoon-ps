while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    a = []
    for i in range(n):
        src, dst, stt, dur = map(int, input().split())
        a.append([stt, stt+dur-1])
    for i in range(m):
        st, du = map(int, input().split())
        c = 0
        for j in range(n):
            if st <= a[j][1] and a[j][0] <= st+du-1:
                c += 1
        print(c)