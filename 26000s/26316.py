n = int(input())
for i in range(1, n+1):
    print(f'Day #{i}')
    c, d = map(int, input().split())
    f = input()
    print(c, d)
    print(f)
    
    dp = [float('inf')] * c
    dp[0] = 0
    
    for j in range(1, c):
        if f[j] == 'X':
            continue
        
        for k in range(0, d+1):
            prev_pos = j - (k + 1)
            if prev_pos >= 0 and f[prev_pos] == '.' and dp[prev_pos] != float('inf'):
                dp[j] = min(dp[j], dp[prev_pos] + 1)
    
    if dp[c-1] == float('inf'):
        print(0)
    else:
        print(dp[c-1])
    
    if i < n:
        print()