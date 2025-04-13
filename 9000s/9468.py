n = int(input())
for _ in range(n):
    a = list(map(int, input().split()))
    c = 0
    for i in range(len(a[1:])-1):
        if a[i] < a[i+1] : c += 1
    print(a[0], c)