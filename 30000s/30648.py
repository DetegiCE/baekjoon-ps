a, b = map(int, input().split())
r = int(input())
d = set()
c = 0
while True:
    if (a, b) in d:
        print(c)
        break
    d.add((a, b))
    if a + b + 2 < r:
        a += 1
        b += 1
    else:
        a //= 2
        b //= 2
    c += 1
