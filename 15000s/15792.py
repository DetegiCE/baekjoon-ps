a, b = map(int, input().split())
print(a//b,end='')
if a % b > 0:
    print('.',end='')
    i = 0
    while a % b > 0 and i < 1000:
        a = a % b * 10
        i += 1
        print(a // b, end='')
