import bisect

t = int(input())
for tc in range(t):
    print(f'Case #{tc+1}:', end=' ')
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for i in a:
        if not b or i > b[-1]:
            b.append(i)
            continue
        lb = bisect.bisect_left(b, i)
        b[lb] = i
    print(n - len(b))