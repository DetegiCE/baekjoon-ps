d = dict()
while True:
    s = input()
    if s == 'XXXXXX':
        break
    t = list(s)
    t.sort()
    ts = ''.join(t)
    if ts in d: d[ts].append(s)
    else: d[ts] = [s]
while True:
    s = input()
    if s == 'XXXXXX':
        break
    s = list(s)
    s.sort()
    ts = ''.join(s)
    if ts in d:
        for i in sorted(d[ts]):
            print(i)
    else:
        print('NOT A VALID WORD')
    print('******')