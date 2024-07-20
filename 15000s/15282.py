n, m = map(int, input().split())
t = list(map(int, input().split()))
l = list(map(int, input().split()))
t.sort(reverse=True)
l.sort(reverse=True)
tp = 0
lp = 0
c = 0
while True:
    if t[tp] <= l[lp]:
        c += 1
        tp += 1
        lp += 1
    else:
        tp += 1
    if tp == n: break
    if lp == m: break
print(c)