for _ in range(int(input())):
    t, *p = list(map(int, input().split()))
    c = 0
    for i in range(1, len(p)):
        for j in range(i):
            if p[j] > p[i]:
                c += 1
    print(t, c)
