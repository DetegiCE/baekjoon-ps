a = input().split('.')[:-1]
for i in a:
    b = i.split()[::-1]
    print(' '.join(b)+'. ', end='')
