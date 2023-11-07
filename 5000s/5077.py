for _ in range(int(input())):
    a, b = map(int, input().split())
    am = []
    for i in range(a):
        am.append(input())
    c, d = map(int, input().split())
    cm = []
    for i in range(c):
        cm.append(input())
    e = 0
    for i in range(c-a+1):
        for j in range(d-b+1):
            tc = 0
            for k in range(a):
                if cm[i+k][j:j+b] == am[k]:
                    tc += 1
                else: break
            if tc == a:
                e += 1
    print(e)
