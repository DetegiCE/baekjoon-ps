n = int(input())
a = list(map(int, input().split()))
ups = []
dns = []
for i in range(500002):
    ups.append(0)
    dns.append(0)
for i in range(n):
    if a[i] > 0:
        ups[a[i]] += 1
    else:
        dns[-a[i]] += 1
for i in range(1, n+1):
    ups[i] += ups[i-1]
for i in range(n, -1, -1):
    dns[i] += dns[i+1]
c = 0
d = []
for i in range(n+1):
    # 거짓말 수가 i명 (1~i명 이상, i~n명 이하)
    if ups[i] + dns[i] + i == n:
        c += 1
        d.append(i)
print(c)
for i in d:
    print(i, end=' ')
