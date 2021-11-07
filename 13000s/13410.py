n, k = map(int, input().split())
a = [int(str(i)[::-1]) for i in range(n, n*k+1, n)]
print(max(a))
