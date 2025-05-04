n = int(input()) + 1
s = 0
i = 1
while i * i <= n:
    if i * i == n:
        s += 1
        break
    if n % i == 0:
        s += 2
    i += 1
print(s)