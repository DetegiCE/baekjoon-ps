t = int(input())
a = []
for _ in range(t):
    a.append(input().split())
    for i in range(1, 8):
        a[-1][i] = int(a[-1][i])
    sc = a[-1][1] * 10
    ts = a[-1][2:]
    sc += sum(ts) - max(ts) - min(ts)
    a[-1].append(sc)
    a[-1].append(_)
a.sort(key=lambda x: (-x[-2], x[-1]))
th = a[2][-2]
for i in a:
    if i[-2] >= th:
        print(i[0], i[-2])