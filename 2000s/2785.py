n = int(input())
a = list(map(int, input().split()))
a.sort()
c = n
d = 0
while True:
    if c == 1:
        break
    a[0] -= 1
    e = a[-1] + a[-2] + 1
    d += 1
    a.pop()
    a.pop()
    c -= 1
    a.append(e)
    if a[0] == 0:
        a.pop(0)
        c -= 1
print(d)
