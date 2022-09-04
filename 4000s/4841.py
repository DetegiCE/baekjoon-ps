for i in range(int(input())):
    a=input()
    while len(a) > 0:
        print(len(a)-len(a.lstrip(a[0])), a[0], sep='', end='')
        a = a.lstrip(a[0])
    print()