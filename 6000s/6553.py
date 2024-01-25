while True:
    try:
        n, *a = map(int, input().split())
        print(n, end=' ')
        b = [[], []]
        for i in range(n):
            b[0].append(a[i*2])
            b[1].append(a[i*2+1])
        for i in range(n):
            print("%.6f %.6f " % ((b[0][i] + b[0][(i+1)%n])/2, (b[1][i] + b[1][(i+1)%n]) / 2), end='')
        print()
    except:
        break
