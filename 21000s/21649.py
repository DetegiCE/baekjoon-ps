m, n, x, y, c = map(int, input().split())
if m * n % 2 == 0:
    print('equal')
else:
    if x % 2 == y % 2 and c == 0 or x % 2 != y % 2 and c == 1:
        print('black')
    else:
        print('white')
