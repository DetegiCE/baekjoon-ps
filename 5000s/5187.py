for i in range(int(input())):
    print(f'Data Set {i+1}:')
    m, n = map(int,input().split())
    r = [0]
    for j in range(m):
        r.append(int(input()))
    we = 0
    for j in range(n):
        h, w, d, mm = map(int,input().split())
        we += h * w * d * r[mm]
    print(we)