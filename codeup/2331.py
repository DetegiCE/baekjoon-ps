def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)

a, b, c = map(int, input().split())
g1 = a * b // gcd(a, b)
g = g1 * c // gcd(g1, c)

a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]
b = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30]
y = 2100
m = 1
d = 1
w = 0
# check the day after g days
for i in range(g):
    d += 1
    w += 1
    if y % 4 == 0 and y % 100 != 0 or y % 400 == 0:
        if d > b[m-1]:
            d = 1
            m += 1
            if m > 11:
                m = 1
                y += 1
    else:
        if d > a[m-1]:
            d = 1
            m += 1
            if m > 11:
                m = 1
                y += 1
w %= 7
print('%4d-%02d-%02d ' % (y, m, d), end='')
if w == 0: print('FRI')
elif w == 1: print('SAT')
elif w == 2: print('SUN')
elif w == 3: print('MON')
elif w == 4: print('TUE')
elif w == 5: print('WED')
elif w == 6: print('THU')

