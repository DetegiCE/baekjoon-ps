a = [0, 1]
n = int(input())
for i in range(2, n+1):
    a.append(a[-1] + a[-2])
if n == 0: print(0)
else: print(a[-1])