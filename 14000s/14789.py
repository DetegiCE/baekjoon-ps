t = int(input())
for tc in range(1, t+1):
    print(f'Case #{tc}: ', end='')
    s, k = input().split()
    k = int(k)
    a = []
    for i in s:
        if i == '+': a.append(True)
        else: a.append(False)
    f = 0
    for i in range(len(s)-k):
        if not a[i]:
            f += 1
            for j in range(i, i+k):
                a[j] = not a[j]
    
    b = True
    chk = True
    for i in range(len(s)-k, len(s)):
        if not a[i]: chk = False
        else: b = False
    if b: f += 1
    if chk: b = True
    if b: print(f)
    else: print('IMPOSSIBLE')