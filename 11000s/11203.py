a = input().strip()
if ' ' in a:
    h, l = a.split()
    h = int(h)
    s = 1
    for i in l:
        if i == 'L': s *= 2
        else: s = s * 2 + 1
    print(2**(h+1)-s)
else:
    print(2**(int(a)+1)-1)
