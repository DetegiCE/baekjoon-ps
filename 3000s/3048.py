n1, n2 = map(int, input().split())
a = input()[::-1]
b = input()
t = int(input())
s = list(a + '_' * len(b))
u = 0
for i in range(n1-1, -1, -1):
    pos = min(max(t - u, 0), len(b))
    u += 1
    s[i], s[pos+i] = s[pos+i], s[i]
v = 0
for i in s:
    if i == '_':
        print(b[v], end='')
        v += 1
    else: print(i, end='')