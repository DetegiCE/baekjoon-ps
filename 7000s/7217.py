n, k = map(int, input().split())
h = [0]
for i in range(n):
    h.append(0)
for i in range(k):
    h[int(input())] = 1
cnt = 0
w = 1
for i in range(1, n+1):
    if i == 1:
        cnt += 1
    elif h[i] == 1:
        w = 1
        cnt += 1
    elif w == 0:
        w = 1
        cnt += 1
    else:
        w = 0
print(cnt)
