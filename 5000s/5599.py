n = int(input())
m = int(input())
a = [i+1 for i in range(n*2)]
for _ in range(m):
    k = int(input())
    if k == 0:
        b = [0 for _ in range(n*2)]
        for i in range(n):
            b[i*2] = a[i]
            b[i*2+1] = a[i+n]
        for i in range(n*2):
            a[i] = b[i]
    else:
        b = [0 for _ in range(n*2)]
        for i in range(k):
            b[i] = a[i]
        for i in range(k, n*2):
            a[i-k] = a[i]
        for i in range(n*2-k, n*2):
            a[i] = b[i-(n*2-k)]
print(*a, sep='\n')