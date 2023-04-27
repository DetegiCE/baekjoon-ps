n, m, k = map(int, input().split())
if n < m+k-1 or n > m*k:
    print(-1)
    exit(0)
a = [i for i in range(n)]
st = 0
for i in range(m):
    en = min(st+k, n-m+i+1)
    # print(f'[{st}, {en})')
    for j in range(min(n+1,en)-1, st-1, -1):
        print(a[j]+1, end=' ')
    st = en
