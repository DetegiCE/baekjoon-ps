a = input()
b = input()
aset = set()
bset = set()
for i in range(len(a)):
    if a[i] == '0':
        aset.add(int(a[:i] + '1' + a[i+1:], 2))
    else:
        aset.add(int(a[:i] + '0' + a[i+1:], 2))

for i in range(len(b)):
    if b[i] == '0':
        bset.add(int(b[:i] + '1' + b[i+1:], 3))
        bset.add(int(b[:i] + '2' + b[i+1:], 3))
    elif b[i] == '1':
        bset.add(int(b[:i] + '0' + b[i+1:], 3))
        bset.add(int(b[:i] + '2' + b[i+1:], 3))
    else:
        bset.add(int(b[:i] + '0' + b[i+1:], 3))
        bset.add(int(b[:i] + '1' + b[i+1:], 3))
print(list(aset & bset)[0])