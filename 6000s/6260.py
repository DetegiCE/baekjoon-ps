a = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
b = [2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9]
c = [1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4]
pad = [[],[],list('CAB'),list('FDE'),list('IGH'),list('LJK'),list('OMN'),list('SPQR'),list('VTU'),list('ZWXY')]
d = dict()
for i in range(26):
    d[a[i]] = [b[i], c[i]]
    d[a[i].lower()] = [b[i], c[i]]

while True:
    s = input()
    if s == '#':
        break
    for i in range(len(s)):
        key = d[s[i]][0]
        time = d[s[i]][1] - i - 1
        time %= len(pad[key])
        if 65 <= ord(s[i]) <= 90:
            print(pad[key][time],end='')
        else:
            print(pad[key][time].lower(), end='')
    print()
