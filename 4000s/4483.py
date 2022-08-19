t=int(input())
for i in range(t):
    print(f'Test set {i+1}:')
    a=[]
    b=[]
    n=int(input())
    for j in range(n):
        c=input()
        a.append(c)
    m=int(input())
    for j in range(m):
        c=input().split()
        b.extend(c)
    for i in a:
        if i in b:
            print(f'{i} is present')
        else:
            print(f'{i} is absent')
    print()