n = int(input())
a = [int(input()) for _ in range(n)]
b = [int(input()) for _ in range(n)]
a.sort()
b.sort()
print(sum([abs(a[i]-b[i]) for i in range(n)]))