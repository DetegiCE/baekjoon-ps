for _ in range(int(input())):
    n = int(input())
    p = input()
    q = input()
    b = 0
    w = 0
    for i in range(n):
        if p[i] != q[i]:
            if q[i] == 'B': b += 1
            else: w += 1
    print(max(b, w))