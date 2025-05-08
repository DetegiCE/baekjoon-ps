t = int(input())
for tc in range(1, t+1):
    print(f'Case #{tc}:', end=' ')
    l, r = map(int, input().split())
    m = min(l, r)
    print(m*(m+1)//2)