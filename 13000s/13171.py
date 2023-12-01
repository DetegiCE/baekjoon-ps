a = int(input())
x = int(input())
mod = 1000000007
b = [a%mod]
for i in range(70):
    b.append((b[-1]*b[-1])%mod)
c = []
for i in range(70):
    if x & (2**i) > 0:
        c.append(b[i])
# print(c)
if len(c) == 0:
    print(0)
else:
    d = 1
    for i in c:
        d *= i
        d %= mod
    print(d)
