n = int(input())
a = [0] + [int(input()) for _ in range(n)] + [0]
for i in range(1, n+1):
    if a[i-1] <= a[i] and a[i] >= a[i+1]:
        print(i)