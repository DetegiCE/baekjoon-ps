from itertools import accumulate as acc
n, q = map(int, input().split())
a = list(map(int, input().split()))
b = [0]
for i in range(n-1):
    b.append(abs(a[i] - a[i+1]))
c = list(acc(b))
for i in range(q):
    d, e = map(int, input().split())
    print(c[e-1]-c[d-1])