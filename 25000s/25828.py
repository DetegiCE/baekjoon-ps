g, p, t = map(int, input().split())
one = g * p
two = g + p * t
if one == two: print(0)
elif one > two: print(2)
else: print(1)