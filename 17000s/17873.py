a = input()
b = a.split('-')
if len(b) < 2:
    print('NO')
    exit(0)
c = b[0]
d = '-'.join(b[1:])
if not (2 <= len(c) <= 8):
    print('NO')
    exit(0)
if not (1 <= len(d) <= 24):
    print('NO')
    exit(0)
print('YES')