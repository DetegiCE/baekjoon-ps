d = {}
b = 'ABCDEFGHIJKLMNOPRSTUVWXY'
c = '222333444555666777888999'
e = dict(zip(b,c))
for _ in range(int(input())):
    a = input().replace('-','')
    a = a.replace('Q','').replace('Z','')
    for i in e:
        a = a.replace(i,e[i])
    if a not in d:
        d[a] = 0
    d[a] += 1
dv = list(d.values())
if dv.count(1) == len(d):
    print('No duplicates.')
else:
    ev = list(d.items())
    ev.sort(key=lambda x: x[0])
    for i in ev:
        if i[1] == 1: continue
        else: print(i[0][:3]+'-'+i[0][3:]+' '+str(i[1]))
