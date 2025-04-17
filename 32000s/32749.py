n, t = map(int, input().split())
a = input()
b = []
l = 2**(n-t)
for i in range(0, 2**n, l):
    b.append(a[i:i+l])
b.sort()
print(b[-1])