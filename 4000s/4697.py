from math import ceil
while True:
    n, w, l, h, a, m = map(int, input().split())
    if n == 0:
        break
    door = 0
    for i in range(m):
        p, q = map(int, input().split())
        door += p * q
    print(int(ceil(((w*l+l*h+h*w)*2-w*l-door)*n/a)))
    
