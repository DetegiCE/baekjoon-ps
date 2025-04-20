m = dict()
for i in range(26):
    a, b = input().split()
    m[a] = b
n = int(input())
d = dict()
for i in range(n):
    a = input()
    s = ''
    for j in a:
        s += m[j]
    d[s] = a
while True:
    m = int(input())
    if m == 0: break
    ans = []
    y = [input() for _ in range(m)]
    f = 0
    for i in y:
        if i in d:
            ans.append(d[i])
        else:
            print(f'{i} not in dictionary.')
            f = 1
            break
    if f == 0:
        print(' '.join(ans))