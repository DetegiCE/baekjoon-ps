from sys import stdin
input = stdin.readline
a = [0 for _ in range(11)]
for _ in range(2047):
    b = list(map(int, input().rstrip().split()))
    for i in range(11):
        a[i] ^= b[i]
for i in range(11):
    print(a[i], end=' ')
