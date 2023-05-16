from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    a, b = map(int, input().split())
    if a*2 <= b and b % a == 0:
        print(1)
    else:
        print(0)
