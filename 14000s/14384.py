for tc in range(1, int(input())+1):
    print(f'Case #{tc}:', end=' ')
    a = input()
    c = 0
    for i in range(len(a) - 1):
        if a[i] != a[i+1]:
            c += 1
    if a[-1] == '-': c += 1
    print(c)