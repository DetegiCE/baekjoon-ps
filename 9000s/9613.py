from itertools import combinations
from math import gcd

def sol():
    a = list(map(int,input().split()))
    c = list(combinations(a[1:], 2))
    s = 0
    for p, q in c:
        s += gcd(p, q)
    print(s)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        sol()