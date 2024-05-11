n = int(input())
k = int(input())
for _ in range(k):
    a, b = map(int, input().split())
    if a + b <= n + 1:
        print('312'[min(a, b)%3])
    else:
        print('123'[(n-max(a,b))%3])
