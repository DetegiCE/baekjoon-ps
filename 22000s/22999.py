for i in range(int(input())):
    n, k = map(int,input().split())
    a = input()
    sp = 0
    for j in range(len(a)//2):
        if a[j] != a[n-1-j]:
            sp += 1
    print('Case #'+str(i+1), end=': ')
    print(abs(sp-k))