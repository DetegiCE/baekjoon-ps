from sys import stdin
input = stdin.readline
def chk(a):
    return all([1 in a, 2 in a, 3 in a, 4 in a, 5 in a, 6 in a])

t = int(input())
for tc in range(1, t+1):
    print(f'Case#{tc}: ', end='')
    a = [list(map(int, input().split())) for _ in range(6)]
    f = True
    for i in range(6):
        if not chk(a[i]): f = False
        if not chk([a[0][i], a[1][i], a[2][i], a[3][i], a[4][i], a[5][i]]): f = False
        if not chk([a[0][0], a[1][1], a[2][2], a[3][3], a[4][4], a[5][5]]): f = False
        if not chk([a[0][5], a[1][4], a[2][3], a[3][2], a[4][1], a[5][0]]): f = False
    for i in range(0, 6, 2):
        if not chk([a[i][0], a[i][1], a[i][2], a[i+1][0], a[i+1][1], a[i+1][2]]): f = False
        if not chk([a[i][3], a[i][4], a[i][5], a[i+1][3], a[i+1][4], a[i+1][5]]): f = False
    if f: print(1)
    else: print(0)