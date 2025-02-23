d = dict()
for _ in range(int(input())):
    a, b = input().split(' = ')
    d[a] = b
for _ in range(int(input())):
    input()
    c = input().split()
    for i in c:
        if i in d:
            print(d[i], end=' ')
        else: print(i, end=' ')
    print()