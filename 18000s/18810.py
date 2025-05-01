n = int(input())
mna, mxa = map(int, input().split())
mnb, mxb = map(int, input().split())
a = [int(input()) for _ in range(n)]
s = 0
r = 0
for i in a:
    s += i//2
    r += i%2
mn1, mx1 = max(0, mna-s), min(r, mxa-s)
mn2, mx2 = max(0, s+r-mxb), min(r, s+r-mnb)
if max(mn1, mn2) <= min(mx1, mx2): print('Yes')
else: print('No')