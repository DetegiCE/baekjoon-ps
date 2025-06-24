a = int(input())
al = [int(input()) for _ in range(a)]

b = int(input())
bl = [int(input()) for _ in range(b)]

i = j = 0
sa = sb = 0
c = 0
d = 0
e = 0

while i < a or j < b:
    if j == b or (i < a and al[i] < bl[j]):
        t = al[i]; i += 1
        sa += 1
    else:
        t = bl[j]; j += 1
        sb += 1

    if t <= 1440:
        c += 1

    dif = sa - sb
    if dif:
        f = 1 if dif > 0 else -1
        if e and f != e:
            d += 1
        e = f

print(c)
print(d)
