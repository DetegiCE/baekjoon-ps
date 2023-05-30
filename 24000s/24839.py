from sys import stdin
input = stdin.readline
for i in range(int(input())):
    print(f'Case #{i+1}', end=': ')
    a = input().rstrip()
    b = input().rstrip()
    acur = 0
    for j in b:
        if j == a[acur]:
            acur += 1
        if acur == len(a):
            break
    if acur == len(a):
        print(len(b)-len(a))
    else:
        print('IMPOSSIBLE')
