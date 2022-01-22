a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
times = 0
if a < 0:
    times += c * (0 - a)
    times += d
    times += e * b
else:
    times += e * (b - a)
print(times)
