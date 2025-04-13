from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(input().rstrip())[::-1]
    b = []
    while len(a) > 0:
        b.append(a[-1])
        a.pop()
        while len(b) >= 3 and ''.join(b[-3:]) == 'ABB':
            b.pop()
            b.pop()
            b.pop()
            b.append('B')
            a.append('A')
    print(''.join(b))