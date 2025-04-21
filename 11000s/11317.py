n = int(input())
for _ in range(n):
    a, b, c, s, t = map(int, input().split())
    if b*b-4*a*c < 0:
        print('No')
        continue
    xm = (-b-(b*b-4*a*c)**0.5)/(a*2)
    xp = (-b+(b*b-4*a*c)**0.5)/(a*2)
    if s <= xm <= t or s <= xp <= t:
        print('Yes')
    else: print('No')