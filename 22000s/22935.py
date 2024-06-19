for _ in range(int(input())):
    a = int(input())
    r = (a-1) % 28
    if r <= 13:
        b = r + 1
        print(('0000'+bin(b)[2:])[-4:].replace('0','V').replace('1','딸기'))
    else:
        b = 29 - r
        print(('0000'+bin(b)[2:])[-4:].replace('0','V').replace('1','딸기'))
