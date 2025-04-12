a = input()
print(len(a), end=' ')
x = 0
for i in a:
    if int(i) % 2 == 1:
        x *= 2
        x += 1
    else:
        x *= 2
y = 0
for i in a:
    if int(i) // 2 == 1:
        y *= 2
        y += 1
    else:
        y *= 2
print(x, y)