from sys import stdin
from collections import deque
input = stdin.readline
for _ in range(int(input())):
    mx = 0
    n = input().rstrip()
    a = deque([])
    a.append([n, 0])
    while a:
        af = a.popleft()
        mx = max(mx, af[1])
        if len(af[0]) > 1:
            mxv = -1
            for i in range(1, len(af[0])):
                mxv = max(mxv, int(af[0][:i]) * int(af[0][i:]))
            a.append([str(mxv), af[1]+1])
    print(mx)