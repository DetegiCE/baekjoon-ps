def f(a):
    b = 2
    i = 2
    while i * i <= a:
        if i * i == a:
            b += 1
        elif a % i == 0:
            b += 2
        if b > 4:
            return False
        i += 1
    if b == 4: return True
    else: return False

n = int(input())
m = int(input())
c = 0
for i in range(n, m+1):
    if f(i):
        c += 1
print(f'The number of RSA numbers between {n} and {m} is {c}')