t = int(input())
for i in range(t):
    n = int(input())
    a = [[1, n]]
    j = 2
    while j * j <= n:
        if j * j == n:
            a.append([j, j])
            break
        if n % j == 0:
            a.append([j, n//j])
        j += 1
    f = 0
    for j in a:
        for k in a:
            if abs(j[0]-j[1]) == k[0]+k[1]:
                f = 1
                break
        if f == 1: break
    if f == 1: print(f'{n} is nasty')
    else: print(f'{n} is not nasty')