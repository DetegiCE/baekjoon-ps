for _ in range(int(input())):
    n = int(input())
    if n == 1: 
        print('1 dolphin')
        continue
    elif n == 2: 
        print('1 jump')
        continue

    num = 1
    while n > num * 3:
        n -= num * 3
        num += 1
    
    if n <= num: print(num, 'dolphins')
    elif n <= num*2: print(num, 'jumps')
    else: print('splash')