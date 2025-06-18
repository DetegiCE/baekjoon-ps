t = int(input())
for tc in range(1, t+1):
    print(f'Scenario #{tc}:')
    a = list(map(int, input().split()))
    b = a[0]
    a = a[1:]
    c = 0
    for i in range(b):
        mnv = a[i]
        mni = i
        for j in range(i+1, b):
            if mnv > a[j]:
                mnv = a[j]
                mni = j
        c += mni - i
        a[i:mni+1] = [a[mni]] + a[i:mni]
    print(c)
    print()