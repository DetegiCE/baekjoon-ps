a, b = input().split()
w = []
p = 0
if a == '1' or a == '3':
    for i in range(0, len(b)):
        if i == 0:
            w.append(b[i])
        else:
            if 65 <= ord(b[i]) <= 90:
                w.append(b[i])
            else:
                w[-1] += b[i]
elif a == '2':
    w = b.split('_')
for i in range(len(w)):
    w[i] = w[i].lower()
for i in range(len(w)):
    if i == 0:
        print(w[0], end='')
    else:
        print(w[i].capitalize(), end='')
print()
print('_'.join(w))
for i in range(len(w)):
    print(w[i].capitalize(), end='')
