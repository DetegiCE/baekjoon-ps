n = int(input())
s = 1
for i in range(1, n+1):
    s *= i
    while s % 10 == 0:
        s //= 10
    if s >= 1000000000000000:
        s %= 1000000000000000
while s % 10 == 0:
    s //= 10
print(str(s%100000).zfill(5))
