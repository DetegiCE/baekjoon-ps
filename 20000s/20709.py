mnidx = 0
mnval = 9999999999
for i in range(int(input())):
    a,b=input().split()
    a=int(a)
    if b.count('0') > 0 and b.count('1') > 0:
        if b.count('2') > 1:
            if mnval > a:
                mnval = a
                mnidx = i+1
print(mnidx)