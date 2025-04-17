n = int(input())
a = set([input() for _ in range(n)])
t = int(input())
for tc in range(1, t+1):
    print(f'Email {tc} is ', end='')
    v = []
    while True:    
        b = input()
        if b == '-1':
            break
        if b not in a:
            v.append(b)
    if v:
        print('not spelled correctly.')
        for i in v:
            print(i)
    else:
        print('spelled correctly.')
print('End of Output', end='')