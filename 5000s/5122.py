for case in range(int(input())):
    print(f'Data Set {case+1}:')
    a = list(map(int, input().split()))
    b = int(input())
    c = 0
    for i in range(5):
        if i == 3: c = c*18+a[i]
        else: c = c*20+a[i]
    d = b - c - 584054
    if d < 0:
        print('It\'s a hoax!\n')
    elif d == 0:
        print('Panic!\n')
    else:
        print(d, end='\n\n')
