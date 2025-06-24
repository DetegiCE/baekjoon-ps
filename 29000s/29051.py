a = list("abcdefghijklmnopqrstuvwxyz".upper())
b = [2,1,1,1,2, 2,1,3,3,2, 3,1,1,1,1, 1,1,2,1,2, 1,1,1,2,2,1]
d = dict(zip(a, b))
c = input()
e = 0
for i in c:
    e += d[i]
print(e)