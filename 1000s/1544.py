t = int(input())
s = set()
for _ in range(t):
    a = input()
    if not s:
        s.add(a)
        continue
    if a in s:
        continue
    f = 0
    for i in range(1, len(a)):
        b = a[i:] + a[:i]
        if b in s:
            f = 1
            break
    if f == 0:
        s.add(a)
print(len(s))