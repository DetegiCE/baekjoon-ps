from math import gcd

n = s = -1
a = []
d = []
g = 0

if __name__ == '__main__':
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    for i in a:
        d.append(abs(s-i))
    if n == 1:
        print(d[0])
    else:
        g = gcd(d[0], d[1])
        for i in range(2, n):
            g = gcd(g, d[i])
        print(g)