n, m = map(int, input().split())
for _ in range(n): input()
c = {'R':0, 'G':0, 'B':0}
for _ in range(m):
    a, b, d = input().split()
    c[d] += 1
if c['G'] % 2 == 0:
    if c['R'] > c['B']: print('jhnah917')
    else: print('jhnan917')
else:
    if c['R'] >= c['B']: print('jhnah917')
    else: print('jhnan917')
    