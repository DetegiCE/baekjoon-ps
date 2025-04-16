n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
b = list(map(int, input().split()))
c = [0 for _ in range(n+2)]
for i in b:
    c[i] = a[i]
for i in range(1, n+1):
    if c[i] == 0:
        for j in range(1, 6):
            if c[i-1] == j or c[i+1] == j or a[i] == j:
                continue
            c[i] = j
            break
print(*c[1:-1])