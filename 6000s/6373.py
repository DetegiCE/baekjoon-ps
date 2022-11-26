from math import gcd
while True:
    try:
        a = input()
        b = []
        for i in range(len(a)):
            b.append(a[i:]+a[:i])
        b = list(map(int, b))
        b.sort()
        f = 0
        for i in range(len(a)):
            if b[i] != b[0] * (i+1):
                f = 1
                print(f'{a} is not cyclic')
                break
        if f == 0:
            print(f'{a} is cyclic')
    except:
        break