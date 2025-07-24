n = int(input())
if n <= 1: print('BROKEN')
elif n == 2: print('SAFE')
elif n % 2 == 0: print('BROKEN')
else:
    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            print('BROKEN')
            exit(0)
    print('SAFE')