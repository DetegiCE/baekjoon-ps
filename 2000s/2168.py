from math import gcd
n, m = map(int, input().split())
print(n+m-gcd(n,m))