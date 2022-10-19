from math import comb
r, c, w = map(int, input().split())
s = 0
for i in range(r-1, r+w-1):
    for j in range(c-1, c+i-r+1):
        s += comb(i, j)
print(s)