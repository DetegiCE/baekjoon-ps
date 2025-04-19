for tc in range(1, int(input())+1):
    print(f'Case #{tc}: ', end='')
    n, k = map(int, input().split())
    if (k+1) % (2**n) == 0: print('ON')
    else: print('OFF')