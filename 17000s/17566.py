m, b, s = map(int, input().split())
a = []
for _ in range(b):
    a.append(int(input()[::-1], 2))
c = 0
for i in range(b):
    if (a[i] >> (m-1)) % 2 == 1:
        c |= a[i]
if c == 0: print(0)
else: print(bin(c)[2:].count('1')-1)