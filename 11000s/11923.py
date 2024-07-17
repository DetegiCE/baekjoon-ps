n, c = map(int, input().split())
w = list(map(int, input().split()))
mx = 0
for i in range(n):
    s = 0
    cnt = 0
    idx = i
    while True:
        if idx == n:
            break
        if s + w[idx] <= c:
            s += w[idx]
            cnt += 1
        idx += 1
    mx = max(mx, cnt)
print(mx)
