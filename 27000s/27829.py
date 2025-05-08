t = int(input())
for _ in range(t):
    input()
    n, m = map(int, input().split())
    mg = max(list(map(int, input().split())))
    mm = max(list(map(int, input().split())))
    if mg >= mm: print('Godzilla')
    else: print('MechaGodzilla')