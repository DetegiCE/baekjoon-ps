for tc in range(1, int(input())+1):
    print(f'Case #{tc}: ', end='')
    n = int(input())
    a = input().split()
    b = []
    r = []
    for i in a:
        if i[-1] == 'B':
            b.append(int(i[:-1]))
        else: r.append(int(i[:-1]))
    b.sort(reverse=True)
    r.sort(reverse=True)
    c = 0
    for i in range(min(len(b), len(r))):
        c += b[i] + r[i] - 2
    print(c)