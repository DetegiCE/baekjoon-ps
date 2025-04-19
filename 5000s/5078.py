def sz(a):
    return 'SML'.find(a[0])
def clr(a):
    return 'KNOPRW'.find(a[1])
while True:
    n = int(input())
    if n == 0: break
    a = [input() for _ in range(n)]
    n = int(input())
    a += [input() for _ in range(n)]
    a.sort(key=lambda x: (sz(x), clr(x)))
    print(*a, end=' ')
