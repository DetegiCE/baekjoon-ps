from math import sqrt, log, sin
x = [1]
for i in range(1, 1000001):
    x.append(x[int(i-sqrt(i))] + x[int(log(i))] + x[int(i * sin(i) * sin(i))])
    x[-1] %= 1000000
while True:
    a = int(input())
    if a == -1:
        break
    print(x[a])