n, t = map(int, input().split())
a = list(map(int, input().split()))
if t % 2 == 0: print(*a)
else: print(*reversed(a))