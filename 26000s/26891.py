from math import ceil
n = int(input())
if n == 1:
    print(4)
    exit()
if n == 2:
    print(6)
    exit()
m = n*n
for i in range(1, int(n**0.5)+1):
    x = i
    y = int(ceil(n/i))
    m = min(m, (x+1)*(y+1))
print(m)
