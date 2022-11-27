n=int(input())
a=[]
for _ in range(n):
    a.append(input())
s=0
for i in range(n):
    if a[i] in ['ethiopia', 'kenya', 'tanzania']:
        s += 50
    elif a[i] == 'namibia':
        flg = 0
        s += 40
        for j in range(i):
            if a[j] == 'south-africa':
                flg = 1
                break
        if flg == 0:
            s += 100
    elif a[i] == 'zambia':
        s += 50
        if i > 0 and a[i-1] == 'zimbabwe':
            s -= 30
    elif a[i] == 'zimbabwe':
        s += 30
        if i > 0 and a[i-1] == 'zambia':
            s -= 30
print(s)