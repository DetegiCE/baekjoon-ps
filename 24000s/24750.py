import math
a, b, c, d = map(int, input().split())
g = math.gcd(a, b)
if d % g != 0:
    print("No solution.")
    exit(0)
t_min = (d + a - 1) // a
t = 1e18
for i in range(t_min, 10001):
    e = i * a - d
    if e < c:
        continue
    if e % b == 0:
        t = i
        b = e // b
        break
if t == 1e18:
    print("No solution.")
    exit(0)
ts = "truck" if t == 1 else "trucks"
bs = "boat" if b == 1 else "boats"
print(f"We need {t} {ts} and {b} {bs}.")
