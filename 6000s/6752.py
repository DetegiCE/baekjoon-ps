t = int(input())
c = int(input())
a = [int(input()) for _ in range(c)]
a.sort()

b = 0
c = 0
for i in a:
    if c + i > t: break
    c += i
    b += 1
print(b)