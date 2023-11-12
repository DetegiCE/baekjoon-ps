n = int(input())
a = input().split()
b = input().split()
d = dict()
for i in range(n):
    d[a[i]] = b[i]
for i in range(n):
    if d[b[i]] != a[i]:
        print('bad')
        exit(0)
    if d[a[i]] == a[i]:
        print('bad')
        exit(0)
print('good')
