n = int(input())
a = list(map(int, input().split()))
a.sort()
b = a[:len(a)//2]
c = a[len(a)//2:][::-1]
for i in range(n):
    if i < len(b):
        print(b[i], end=' ')
    if i < len(c):
        print(c[i], end=' ')
