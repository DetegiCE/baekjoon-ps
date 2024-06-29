n, x = map(int, input().split())
age = []
fil = []
for _ in range(n):
    a, b = map(int, input().split())
    age.append(a)
    fil.append(b)
c = 0
for i in range(1, n):
    if fil[i] != fil[i-1]:
        if fil[i] == 1 and age[i] > age[i-1] or fil[i-1] == 1 and age[i-1] > age[i]:
            age[i], age[i-1] = age[i-1], age[i]
    if age[i-1] <= x and fil[i-1] == 1 or age[i-1] > x and fil[i-1] == 0:
        c += 1
if age[n-1] <= x and fil[n-1] == 1 or age[n-1] > x and fil[n-1] == 0:
    c += 1
print(c)