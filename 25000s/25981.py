n, k = map(int, input().split())
a = list(map(int, input().split()))
b = 0
while True:
    c = True
    for i in range(1, n):
        if a[i] < a[i-1]:
            c = False
            break
    if c:
        break
    for i in range(n-k+1):
        a[i:i+k] = sorted(a[i:i+k])
    b += 1
print(b)