for tc in range(1, int(input())+1):
    print(f'Case #{tc}:', end=' ')
    k, v = map(int, input().split())
    ans = 0
    for i in range(-v, v+1):
        for j in range(-v, v+1):
            if abs(i+j) > v:
                continue
            lef = max(0, -i, -i-j)
            rig = min(k, k-i, k-i-j)
            ans += rig - lef + 1
    print(ans)