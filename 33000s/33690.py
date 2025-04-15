n = int(input())
cnt = 0
for i in range(10):
    if i <= n: cnt += 1
for len in range(2, 11):
    for i in range(1, 10):
        t = 0
        for j in range(len):
            t = t * 10 + i
        if t <= n:
            cnt += 1
print(cnt)