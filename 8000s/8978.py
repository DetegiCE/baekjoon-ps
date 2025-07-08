n, k = map(int, input().split())
p = int(input())
t = [[] for _ in range(n)]
for i in range(p):
    a = input()
    count1 = [0 for _ in range(n)]
    for j in range(n):
        if len(t[j]) == k:
            count1[j] = 1e18
            continue
        for l in t[j]:
            if l[0] == a[0]:
                count1[j] += 1
    mc1 = min(count1)
    mc1cnt = 0
    for j in count1:
        if j == mc1:
            mc1cnt += 1
    if mc1cnt == 1:
        for j in range(n):
            if count1[j] == mc1:
                t[j].append(a)
                break
        continue
    mc2 = 1e18
    mci = -1
    for j in range(n):
        if count1[j] == mc1:
            mc2 = min(mc2, len(t[j]))
    mc2cnt = 0
    for j in range(n):
        if count1[j] == mc1 and len(t[j]) == mc2:
            mc2cnt += 1
            if mci == -1: mci = j
    if mc2cnt == 1:
        for j in range(n):
            if count1[j] == mc1 and len(t[j]) == mc2:
                t[j].append(a)
                break
        continue
    t[mci].append(a)
for i in t:
    print(len(i), end=' ')