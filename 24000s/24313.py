a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())
v1 = a1 * n0 + a0
v2 = c * n0
if v1 <= v2 and a1 <= c: print(1)
else: print(0)
