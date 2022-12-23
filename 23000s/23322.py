n, k = map(int, input().split())
a = list(map(int, input().split()))
print(sum(a)-a[0]*n, n-a.count(a[0]))