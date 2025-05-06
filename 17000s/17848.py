n, m = map(int, input().split())
cnt = 0
a = [0] + list(map(int, input().split()))
cur = m
visit = [False for _ in range(n+1)]
if a[cur] == m:
    print(0)
    exit(0)

while not visit[cur]:
    visit[cur] = True
    cur = a[cur]
    cnt += 1
    if cur == m:
        break
print(cnt)