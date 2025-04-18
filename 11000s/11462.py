while True:
    a = input()
    if a == 'END':
        break
    a = list(a)
    for i in range(len(a)-1, -1, -1):
        if a[i] != '0':
            a[i] = str(int(a[i])-1)
            break
    print(int(''.join(a)))