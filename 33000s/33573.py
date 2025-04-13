from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    n = input().rstrip()
    m = n[::-1]
    a = int(n)
    b = int(m)
    if int(a**0.5) == a**0.5 and int(b**0.5) == b**0.5:
        print('YES')
    else: print('NO')