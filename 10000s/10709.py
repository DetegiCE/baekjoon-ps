n, m = map(int, input().split())
for _ in range(n):
    a = input()
    s = -1
    for i in a:
        if i == 'c':
            s = 0
            print(s, end=' ')
        elif i == '.':
            if s == -1:
                print(-1, end=' ')
            else:
                s += 1
                print(s, end=' ')
    print()