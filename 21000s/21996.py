n = int(input())
s = input()
a = []
c = 0
for i in s:
    if i == '.':
        a.append(c)
        c += 1
    else:
        a.append(c)
if n <= 25: print(s)
else:
    if len(set(a[11:-11])) > 1:
        print(s[:9]+'......'+s[-10:])
    else:
        print(s[:11]+'...'+s[-11:])
    
