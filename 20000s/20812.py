k, n = map(int, input().split())
x = list(map(int, input().split()))
s = 0
for i in x: s += i // 10
if s >= (n+9)//10:
    print((n+9)//10)
    exit(0)
r = n-10*s
t = []
for i in x:
    if i % 10 != 0:
        t.append(i % 10)
t.sort()
t.reverse()

p = 0
c = 0
for i in t:
    c += i
    p += 1
    if c >= r: break
print(s + p)