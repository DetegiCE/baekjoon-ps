cnt = 0
while True:
    a=input()
    if a == '0': break
    n,x,y,z=map(int, a.split())
    c=[]
    t=input().split()
    c.extend(t)
    while c[-1] != '?':
        t=input().split()
        c.extend(t)
    state=0
    dialpos=0
    b=[]
    for i in range(0, len(c), 2):
        if i == len(c)-1:
            break
        if i == 0:
            b.append(c[i])
            b.append(int(c[i+1]))
        else:
            if b[-2] == c[i]:
                b[-1] += int(c[i+1])
            else:
                b.append(c[i])
                b.append(int(c[i+1]))
    for i in range(0, len(b), 2):
        if b[i] == 'C':
            if state == 0:
                dialpos -= b[i+1]
                if b[i+1] >= n and dialpos % n == x:
                    state = 1
            elif state == 2:
                dialpos -= b[i+1]
                if b[i+1] < n and dialpos % n == z:
                    state = 3
                elif b[i+1] >= n and dialpos % n == x:
                    state = 1
                else:
                    state = 0
            else:
                dialpos -= b[i+1]
                state = 0
        else:
            if state == 1:
                dialpos += b[i+1]
                if b[i+1] >= n and b[i+1] <= 2*n and dialpos % n == y:
                    state = 2
                else:
                    state = 0
            else:
                dialpos += b[i+1]
                state = 0
    cnt += 1
    if state == 3:
        print(f'Case {cnt}: Open')
    else:
        print(f'Case {cnt}: Closed')