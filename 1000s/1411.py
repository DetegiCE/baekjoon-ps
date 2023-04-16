d = {}
for _ in range(int(input())):
    a = input()
    b = {}
    c = 0
    for i in range(len(a)):
        if a[i] in b:
            a = a[:i] + b[a[i]] + a[i+1:]
        else:
            b[a[i]] = chr(97+c)
            c += 1
            a = a[:i] + b[a[i]] + a[i+1:]
    if a not in d:
        d[a] = 0
    d[a] += 1
s = 0
for i in d:
    s += (d[i] * (d[i]-1) // 2)
print(s)
            
