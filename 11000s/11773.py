import random
a, b = map(int, input().split())
c = list('abcdefghijklmnopqrstuvwxyz')
d = []
for i in range(b):
    e = ''
    for j in range(15):
        e += random.choice(c)
    d.append(e)
print(' '.join(d))
