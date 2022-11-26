def make47(l):
    if l == 1:
        return ['4', '7']
    c = []
    for i in make47(l-1):
        c.append('4'+i)
        c.append('7'+i)
    return c

a,b=input().split()
if len(a) == len(b):
    lst = make47(len(a))
    cnt = 0
    for i in lst:
        if a <= i <= b:
            cnt += 1
    print(cnt)
else:
    cnt = 0
    for i in range(len(a), len(b)+1):
        if i == len(a):
            lst = make47(len(a))
            for j in lst:
                if int(a) <= int(j) <= int(b):
                    cnt += 1
        elif i == len(b):
            lst = make47(len(b))
            for j in lst:
                if int(a) <= int(j) <= int(b):
                    cnt += 1
        else:
            cnt += (2**i)
    print(cnt)