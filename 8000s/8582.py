from sys import stdin
input = stdin.readline
n = int(input())
a = []
b = []
mxa, mxb = 0, 0
for i in range(n):
    a.append(int(input()))
    b.append(0)
for i in range(n):
    if a[i] > mxb:
        mxb = a[i]
    b[i] = mxb
for i in range(n-1, -1, -1):
    if a[i] > mxa:
        mxa = a[i]
    a[i] = mxa
for i in range(n):
    print(b[i], a[i])
