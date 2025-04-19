r, c, v, h = map(int, input().split())
a = [int(input()) for _ in range(v)]
b = [int(input()) for _ in range(h)]

for i in range(v):
    for j in range(a[i]):
        s = i % 2
        for k in range(h):
            for l in range(b[k]):
                if s == 0: print('B', end='')
                else: print('W', end='')
            s += 1
            s %= 2
        print()