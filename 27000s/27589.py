from sys import stdin
input = stdin.readline
n, q = map(int, input().split())
d = dict()
for i in range(n):
    d[input().rstrip()] = i
for i in range(q):
    a, b= input().rstrip().split()
    print(abs(d[a]-d[b])-1)