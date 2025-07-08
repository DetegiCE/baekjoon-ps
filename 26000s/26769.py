n = int(input())
a = sorted(list(map(int, input().split())))
if n < 4: print(0)
else: print(a[-4]**2)
