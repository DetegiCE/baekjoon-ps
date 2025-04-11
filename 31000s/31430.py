def n2s(num):
    t = 'abcdefghijklmnopqrstuvwxyz'
    l = []
    while num > 0:
        l.append(num % 26)
        num //= 26
    while len(l) < 13:
        l.append(0)
    l.reverse()
    s = ''
    for i in l:
        s += t[i]
    return s

t = int(input())
if t == 1:
    a, b = map(int, input().split())
    print(n2s(a+b))
else:
    t = 'abcdefghijklmnopqrstuvwxyz'
    s = input()
    s = s[::-1]
    d = 0
    c = 1
    for i in s:
        d += t.index(i) * c
        c *= 26
    print(d)