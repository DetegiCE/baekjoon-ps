n, k = map(int, input().split())
l = len(str(n))
v = n
for i in range(k):
    if v % k == 0:
        print(i+1)
        exit(0)
    v *= 10 ** l
    v += n
    v %= k
print(-1)