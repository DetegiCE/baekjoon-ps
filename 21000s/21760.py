for _ in range(int(input())):
    n, m, k, d = map(int, input().split())
    a=d*2//(k*n*m*(m-1)+m*m*n*(n-1))
    if a==0:
        print(-1)
    else:
        print(k*n*m*(m-1)*a//2+m*m*n*(n-1)*a//2)
