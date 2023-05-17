from sys import stdout
n, k, m = map(int, input().split())
for _ in range(m):
    for i in range(1, k+1):
        print(i, end=' ')
    stdout.flush()
    input()
