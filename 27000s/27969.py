a = input().split()
b = []
c = 0
s = 0
for i in a:
    # print(i, c, b)
    if i == '[':
        b.append(0)
        c += 1
    elif i == ']':
        c -= 1
        if c == 0:
            s += b[0] + 8
        else:
            b[c-1] += b[c] + 8
        b.pop()
    elif i[0] in '1234567890':
        b[c-1] += 8
    else:
        b[c-1] += len(i) + 12
print(s)
