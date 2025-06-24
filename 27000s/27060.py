a = ''
for _ in range(4): a += input()
b = [0 for _ in range(26)]
for i in a:
    if not (65 <= ord(i) <= 90): continue
    b[ord(i)-65] += 1
mx = max(b)
c = []
for i in range(mx, 0, -1):
    c.append('')
    for j in range(26):
        if b[j] >= i: c[-1] += '*' + (' ' if j < 26 else '')
        else: c[-1] += ('  ' if j < 26 else ' ')
for i in c:
    print(i.rstrip())
for i in range(26):
    if i == 25: print('Z')
    else: print(chr(i+65), end=' ')