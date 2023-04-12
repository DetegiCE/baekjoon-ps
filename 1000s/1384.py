gcnt = 1
while True:
    n = int(input())
    if n == 0:
        break
    a = []
    for i in range(n):
        a.append(input().split())
    ncnt = 0
    print('Group', gcnt)
    gcnt += 1
    for i in range(n):
        for j in range(1, n):
            if a[i][j] == 'N':
                ncnt += 1
                print(a[i-j][0], 'was nasty about', a[i][0])
    if ncnt == 0:
        print('Nobody was nasty')
    print()
    
