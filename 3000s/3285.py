a = input()
b = a
k = int(input())
s = input()
d = ' ' * 26
c = 'A'
for i in range(k-1, 26):
    if len(a) > 0:
        d = d[:i] + a[0] + d[i+1:]
        a = a[1:]
    else:
        while c in b:
            c = chr(ord(c)+1)
        d = d[:i] + c + d[i+1:]
        c = chr(ord(c)+1)
for i in range(0, k-1):
    if len(a) > 0:
        d = d[:i] + a[0] + d[i+1:]
        a = a[1:]
    else:
        while c in b:
            c = chr(ord(c)+1)
        d = d[:i] + c + d[i+1:]
        c = chr(ord(c)+1)
for i in s:
    print(chr(d.index(i)+65), end='')
        
