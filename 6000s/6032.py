n = int(input())
a = []
for _ in range(n):
    j, p = map(int, input().split())
    a.append([j/p, _, j, p])
a.sort(reverse=True)
print(a[0][3]+a[1][3]+a[2][3])
print(a[0][1]+1)
print(a[1][1]+1)
print(a[2][1]+1)