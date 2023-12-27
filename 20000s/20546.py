n = int(input())
a = list(map(int, input().split()))
j, s = n, n
js, ss = 0, 0
for i in a:
    if j >= i:
        js += j//i
        j %= i
for i in range(len(a)-3):
    if a[i] > a[i+1] > a[i+2]:
        ss += s//a[i+3]
        s %= a[i+3]
    if a[i] < a[i+1] < a[i+2]:
        s += ss * a[i+3]
        ss = 0

jf = j + a[-1] * js
sf = s + a[-1] * ss

if jf > sf: print('BNP')
elif jf < sf: print('TIMING')
else: print('SAMESAME')
