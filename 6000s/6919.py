from math import gcd 
a = int(input())
b = int(input())
if a % b == 0:
    print(a // b)
elif a // b < 1:
    g = gcd(a, b)
    na = a // g
    nb = b // g
    print(f'{na}/{nb}')
else:
    g = gcd(a, b)
    na = (a % b) // g
    nb = b // g
    print(f'{a//b} {na}/{nb}')