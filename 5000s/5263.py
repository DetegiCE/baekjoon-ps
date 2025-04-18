n, k = map(int, input().split())
a = [int(input()) for _ in range(n)]
d = dict()
for i in a:
    if i in d: d[i] += 1
    else: d[i] = 1
for i in d:
    if d[i] % k != 0:
        print(i)
        break
