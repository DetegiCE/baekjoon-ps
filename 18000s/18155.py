n, m = map(int, input().split())
a = [input() for _ in range(n)]
l1 = list('01235678')
l2 = list('OLZESBTB')
d = dict(zip(l1, l2))
for _ in range(m):
    b = input()
    for i in d:
        b = b.replace(i, d[i])
    f = 0
    for i in a:
        if i in b:
            print('INVALID')
            f = 1
            break
    if f == 0:
        print('VALID')