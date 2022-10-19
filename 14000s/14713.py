n = int(input())
a = []
for _ in range(n):
    a.append(input().split())
b = input().split()
for i in b:
    flg = 0
    for j in range(n):
        if len(a[j]) == 0:
            continue
        if a[j][0] == i:
            flg = 1
            a[j].pop(0)
            break
    if flg == 0:
        print('Impossible')
        quit()
for i in a:
    if i:
        print('Impossible')
        quit()
print('Possible')
    