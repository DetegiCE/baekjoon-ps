def s(n):
    a = 1
    i = 2
    while i * i <= n:
        if i * i == n:
            a += i
            break
        if n % i == 0:
            a += i
            a += n // i
        i += 1
    return a
t = int(input())
a = list(map(int, input().split()))
for i in a:
    if i == 1:
        print('deficient')
        continue
    b = s(i)
    if b > i: print('abundant')
    elif b < i: print('deficient')
    else: print('perfect')