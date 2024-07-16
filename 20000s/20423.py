s = input().lower()
n = 'cfgjk469'
for i in n:
    if i in s:
        print(-1)
        exit()
m = 'aehstyz'
for i in m:
    s = s.replace(i, i.upper())
a = 'AbdEHilmnopqrSTuvwxYZ0123578'
b = 'Adb3Hilmnoqp72TuvwxY501SEZr8'
d = dict(zip(a, b))

flp = ''
for i in s[::-1]:
    flp += d[i]
ans = s + flp
for i in range(1, len(s)+1):
    ostr = s[:-i] + flp
    if s[-i:] == flp[:i] and s in ostr:
        ans = ostr

ans2 = flp + s
for i in range(1, len(s)+1):
    ostr = flp[:-i] + s
    if flp[-i:] == s[:i] and s in ostr:
        ans2 = ostr

if len(ans) >= len(ans2): print(ans2)
else: print(ans)
