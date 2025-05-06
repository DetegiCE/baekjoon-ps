for tc in range(1, int(input())+1):
    print(f'Scenario #{tc}:')
    a = list(input())
    s = 0
    q = -1
    for i in range(len(a)-1, -1, -1):
        if a[i] == '?':
            q = len(a)-1-i
        else:
            s += int(a[i]) * [9,3,7][(len(a)-1-i)%3]
    for i in range(10):
        if (s+(i*[9,3,7][q%3])) % 10 == 0:
            a[len(a)-1-q] = str(i)
            break
    print(''.join(a))
    print()