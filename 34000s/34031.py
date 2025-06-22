a = input()
b = input()
ap = []
bp = []
if a[0] == '(': ap.append([1,0])
else: ap.append([0,1])
for i in range(1, len(a)):
    if a[i] == '(':
        ap.append([ap[-1][0] + 1, ap[-1][1]])
    else: ap.append([ap[-1][0], ap[-1][1] + 1])
if b[0] == '(': bp.append([1,0])
else: bp.append([0,1])
for i in range(1, len(b)):
    if b[i] == '(':
        bp.append([bp[-1][0] + 1, bp[-1][1]])
    else: bp.append([bp[-1][0], bp[-1][1] + 1])
ad = {}
for i in ap:
    if i[0] < i[1]: break
    else:
        v = i[0] - i[1]
        if v in ad: ad[v] += 1
        else: ad[v] = 1
cnt = 0
cur = 0
for i in range(len(bp)):
    if b[i] == '(':
        cur += 1
    if b[i] == ')' and cur > 0:
        cur -= 1
    if cur > 0: continue
    if bp[i][0] > bp[i][1]: continue
    else:
        v = bp[i][1] - bp[i][0]
        if v in ad: cnt += ad[v]
print(cnt)