t = int(input())
for _ in range(t):
    a, b, k = map(int, input().split())
    s = set([0])
    ans = 1e18
    if 99 % k == 0:
        s.add(a-99//k)
        s.add(b-99//k)
    if k != 1:
        n1 = k * b - a
        d = k - 1
        if n1 % d == 0:
            s.add(n1 // d)
        n2 = k * a - b
        if n2 % d == 0:
            s.add(n2 // d)
    for i in s:
        if i < 0 or i >= a or i >= b: continue
        fa = min(99, a-i)
        fb = min(99, b-i)
        if fa == k * fb or fb == k * fa:
            ans = min(ans, i)
    if ans == 1e18: print(-1)
    else: print(ans)