m = int(input())
d = []
for i in range(m):
    d.append(input())
key = {
    'A': '2', 'B': '2', 'C': '2',
    'D': '3', 'E': '3', 'F': '3',
    'G': '4', 'H': '4', 'I': '4',
    'J': '5', 'K': '5', 'L': '5',
    'M': '6', 'N': '6', 'O': '6',
    'P': '7', 'Q': '7', 'R': '7', 'S': '7',
    'T': '8', 'U': '8', 'V': '8',
    'W': '9', 'X': '9', 'Y': '9', 'Z': '9',
    '1': '1', ' ': '1'
}
n = int(input())
press = input().split()

seq = []
i = 0
while i < n:
    if press[i] == '1':
        seq.append('1')
        i += 1
    else:
        s = []
        while i < n and press[i] != '1':
            s.append(press[i])
            i += 1
        seq.append(''.join(s))
        while i < n and press[i] == '1':
            seq.append('1')
            i += 1

mp = {}
for w in d:
    ks = ''.join(key[i] for i in w)
    if ks not in mp:
        mp[ks] = w

for i in seq:
    if i == '1':
        print(' ', end='')
    else: print(mp.get(i, '*'*len(i)), end='')