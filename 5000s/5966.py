t=int(input())
for i in range(t):
    n,a=input().split()
    c=0
    for j in range(int(n)):
        if a[j] == '>':
            c += 1
        else:
            c -= 1
        if c < 0:
            break
    if c != 0:
        print('illegal')
    else:
        print('legal')