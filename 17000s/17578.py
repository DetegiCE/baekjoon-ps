while True:
    a, b = map(int, input().split())
    if a == 0:
        break
    y = 0
    x = 0
    s = 0
    key = []
    for i in range(a):
        key.append(input())
    v = input()
    for i in v:
        cy = 0
        cx = 0
        for j in range(a):
            if i in key[j]:
                cy = j
                cx = key[j].index(i)
                break
        s += abs(cy-y) + abs(cx-x) + 1
        y = cy
        x = cx
    print(s)
