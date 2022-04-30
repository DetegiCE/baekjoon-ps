a = list()

def f(n):
    if a[n] != -1:
        return a[n]
    a[n] = 1
    for i in range(n-2, 0, -1):
        a[n] += 2 * f(i)
    return a[n]

n = int(input())
for i in range(n+2):
    a.append(-1)
a[0] = 0
a[1] = a[2] = 1
print(f(n))