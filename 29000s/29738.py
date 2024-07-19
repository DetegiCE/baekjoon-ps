for _ in range(int(input())):
    print(f'Case #{_+1}:', end=' ')
    a = int(input())
    if a > 4500: print('Round 1')
    elif a > 1000: print('Round 2')
    elif a > 25: print('Round 3')
    else: print('World Finals')