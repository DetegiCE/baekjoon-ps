from itertools import permutations
a = list(input().split())
a.sort()
mx = -1
for i in permutations(a, 4):
    s = ''.join(i)
    mx = max(mx, int(s))
print(mx)