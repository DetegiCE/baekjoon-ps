while True:
    try:
        m, n = map(int, input().split())
        if n == m:
            print(-1)
        else:
            orig = n * 100 // m
            for i in range(orig + 1, 101):
                if i == 100:
                    print(-1)
                    break
                x = (i * m - 100 * n) // (100 - i)
                if (n+x)*100//(m+x) > orig:
                    print(x)
                    break
                elif (n+x+1)*100//(m+x+1) > orig:
                    print(x+1)
                    break
    except:
        break