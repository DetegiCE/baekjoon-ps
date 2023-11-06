from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    print(min(a*c, abs(a-b)*d+a*d, abs(a-b)*c+b*d))
