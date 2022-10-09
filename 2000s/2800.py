a = input()
an = []
tot = a.count('(')
gnum = []
cnt = -1
for i in range(len(a)):
    if a[i] == '(':
        cnt += 1
        an.append(cnt)
        gnum.append(cnt)
    elif a[i] == ')':
        an.append(gnum[-1])
        del gnum[-1]
    else:
        an.append(-1)
s = set()
for i in range(1, (1 << tot)):
    t = ''
    for j in range(len(a)):
        if an[j] == -1:
            t += a[j]
        elif i & (1 << an[j]) == 0:
            t += a[j]
    s.add(t)
s = list(s)
s.sort()
for i in s:
    print(i)
        