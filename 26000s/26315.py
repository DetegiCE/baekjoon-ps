n = int(input())
for i in range(1, n+1):
    g, p = map(int, input().split())
    wmn = max(0, (p-g+1)//2 if (p-g) % 2 else (p-g)//2)
    wmx = min(g, p//3)
    
    print(f'Team #{i}')
    print(f'Games: {g}')
    print(f'Points: {p}')
    print('Possible records:')

    for j in range(wmx, wmn-1, -1):
        t = p - 3*j
        l = g - p + 2*j
        if t >= 0 and l >= 0:
            print(f'{j}-{t}-{l}')
    print()