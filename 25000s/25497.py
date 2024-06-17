input();a=input()
c = 0
lr = 0
sk = 0
for i in a:
    if 49 <= ord(i) <= 58:
        c += 1
    elif i == 'L':
        lr += 1
    elif i == 'R':
        if lr > 0:
            c += 1
            lr -= 1
        else: break
    elif i == 'S':
        sk += 1
    elif i == 'K':
        if sk > 0:
            c += 1
            sk -= 1
        else: break
print(c)
