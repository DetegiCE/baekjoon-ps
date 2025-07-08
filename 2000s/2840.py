n, k = map(int, input().split())
q = ['?' for _ in range(n)]
v = [0 for _ in range(130)]
for _ in range(k):
    m, c = input().split()
    m = int(m) - 1
    for i in range(m):
        q.append(q[0])
        q.pop(0)
    if q[0] == '?':
        if v[ord(c)] == 1:
            print('!')
            exit(0)
        q.append(c)
        q.pop(0)
        v[ord(c)] = 1
    elif q[0] == c:
        q.append(c)
        q.pop(0)
    else:
        print('!')
        exit(0)
while q:
    print(q[-1], end='')
    q.pop()