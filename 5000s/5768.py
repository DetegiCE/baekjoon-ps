from sys import stdin
input = stdin.readline

def divs(n):
    c = 2
    for i in range(2, int(n**0.5)+1):
        if i * i == n:
            c += 1
            break
        if n % i == 0:
            c += 2
    return c

while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break
    d = 0
    dv = 0
    for i in range(m, n+1):
        e = divs(i)
        if e >= d:
            d = e
            dv = i
    print(dv, d)
    
