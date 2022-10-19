d = dict()
for i in range(int(input())):
    a=input().split('.')[1]
    if a in d:
        d[a] += 1
    else:
        d[a] = 1
sd = sorted(d.items())
for i in sd:
    print(i[0], i[1])