n = int(input())
a = input()
s = set()
x = 0
y = 0
for i in a:
    s.add((x, y))
    if i == 'E': x += 1
    if i == 'W': x -= 1
    if i == 'S': y -= 1
    if i == 'N': y += 1
s.add((x, y))
print(len(s))
