# pypy3
n = int(input())
a = list()
c = [0 for i in range(8002)]
cmx = list()

for i in range(n):
    t = int(input())
    c[t+4000] += 1
    a.append(t)

print(round(sum(a)/n))

a.sort()
print(a[n//2])

maxcnt = max(c)
for i in range(0, len(c)):
    if c[i] == maxcnt:
        cmx.append(i-4000)
if len(cmx) == 1: print(cmx[0])
else: print(cmx[1])

print(max(a) - min(a))