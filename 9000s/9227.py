d = []
t = []
while True:
    a = input()
    if a == '##':
        break
    d.append(a)
while True:
    a = input()
    if a == '#':
        break
    t.append(a)
for l in t:
    s = list(l)
    i = 0
    while i <= len(l) - 4:
        b = ''.join(s[i:i+4])
        if b[0].isalpha() and b[1].isalpha() and b[2].isalpha() and b[3].isalpha():
            for p in d:
                if b[0] == p[0] and b[3] == p[1]:
                    s[i+1] = '*'
                    s[i+2] = '*'
                    break
        i += 1
    print(''.join(s))
