k, s = map(int, input().split())
n = list(map(int, input().split()))
t = 0
c = 0
for i in n:
    if i < k:
        t += i
    else:
        t += k-1
        c += 1
if c == 0:
    print(-1)
else: print(t+1)
