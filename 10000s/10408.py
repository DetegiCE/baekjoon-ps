a = list(input())
s = 0
c = 0
i = 0
while i < len(a):
    if i == len(a)-1:
        s += int(a[len(a)-1])
        c += 1
    else:
        if a[i] == '1' and a[i+1] == '0':
            i += 1
            s += 10
            c += 1
        else:
            s += int(a[i])
            c += 1
    i += 1
print('{:.2f}'.format(s/c))
