n = int(input())
a = 0
for _ in range(n):
    b = input()
    if b.count('.') != 1:
        continue
    c, d = b.split('.')
    if not (0 < len(c) <= 8 and 0 < len(d) <= 3):
        continue
    a += 1
print(a)