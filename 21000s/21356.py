n = int(input())
a = 1111111111
b = 0
while n > 0:
    b += n // a
    n %= a
    a //= 10
print(b)