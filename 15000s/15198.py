from collections import deque
sz = int(input())
n = int(input())
dq = deque([])
for _ in range(n):
    a = input()
    if a in dq:
        dq.remove(a)
        dq.appendleft(a)
    else:
        if len(dq) == sz:
            dq.pop()
        dq.appendleft(a)
for i in dq:
    print(i)