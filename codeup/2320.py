import math

a, b = map(int, input().split())
r = int(input())
c, d = map(int, input().split())
dist = math.sqrt((a-c)**2 + (b-d)**2)
if dist < r:
    print('in')
elif dist > r:
    print('out')
else:
    print('on')