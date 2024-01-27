n, d = map(int, input().split())
m = 0
k = 0
for i in range(n):
    a, b = map(int, input().split())
    t = ((a-2)//d + 2) * ((b-2)//d + 2)
    if t == m: k = max(k, a*b)
    if t > m:
        m = t
        k = a * b
print(k)
