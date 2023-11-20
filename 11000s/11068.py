def b(n, q):
    r = ''
    while n > 0:
        n, m = divmod(n, q)
        r += '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_-'[m]
    if r == '':
        return '0'
    return r[::-1]

for _ in range(int(input())):
    a = int(input())
    f = 0
    for i in range(2, 65):
        c = b(a, i)
        if c == c[::-1]:
            print(1)
            f = 1
            break
    if f == 0:
        print(0)
