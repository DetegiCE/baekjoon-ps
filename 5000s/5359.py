for _ in range(int(input())):
    n, m, c = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = 0
    for i in range(n-m+1):
        mn = min(a[i:i+m])
        mx = max(a[i:i+m])
        if mx - mn <= c:
            cnt += 1
    print(cnt)
