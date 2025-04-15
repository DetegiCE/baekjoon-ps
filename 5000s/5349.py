s = dict()
while True:
    a = input()
    if a == '000-00-0000':
        break
    if a in s: s[a] += 1
    else: s[a] = 1
b = list()
for i in s:
    if s[i] > 1:
        b.append(i)
b.sort()
for i in b:
    print(i)