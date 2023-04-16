for _ in range(int(input())):
    r, c = map(int, input().split())
    print(1)
    for i in range(c):
        print(f'(0,{i})')
    for i in range(1, r):
        if i % 2 == 1:
            for j in range(c-1, 0, -1):
                print(f'({i},{j})')
        else:
            for j in range(1, c):
                print(f'({i},{j})')
    for i in range(r-1, 0, -1):
        print(f'({i},0)')
