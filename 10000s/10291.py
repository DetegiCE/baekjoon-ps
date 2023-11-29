from math import gcd
while True:
    try:
        n, *a = list(map(int, input().split()))
        g = gcd(a[0]-2, a[1]-2)
        for i in range(2, n):
            g = gcd(g, a[i]-2)
        s = sum(a) - 2 * n
        print(g, s//g)
    except:
        break
