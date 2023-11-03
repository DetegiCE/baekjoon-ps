for case in range(int(input())):
    print(f'Data Set {case+1}:')
    n = int(input())
    a = list(map(float, input().split()))
    s = -1
    for i in range(n):
        if s < 0 and 30 <= a[i] <= 30.2:
            s = i
    if s < 0 or s > n-3:
        print('0.00')
    else:
        ans = 101
        for i in range(s+3, n):
            ans = min(ans, a[i])
        print('%.2lf' % (ans-30))
    print()
