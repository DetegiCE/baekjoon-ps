r = int(input())
c = int(input())
a = [input() for _ in range(r)]
v = [[0 for _ in range(c)] for _ in range(r)]
y = 0
x = 0
while True:
    if v[y][x] == 1:
        print('cykel')
        exit(0)
    v[y][x] = 1
    if a[y][x] == 'v':
        y += 1
    elif a[y][x] == '>':
        x += 1
    elif a[y][x] == '^':
        y -= 1
    elif a[y][x] == '<':
        x -= 1
    elif a[y][x] == 'A':
        print('sushi')
        exit(0)
    elif a[y][x] == 'B':
        print('samuraj')
        exit(0)