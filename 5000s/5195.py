k = int(input())
for case in range(k):
    print(f'Data Set {case+1}:')
    n = int(input())
    ls = dict()
    for i in range(n):
        w = input()
        s = int(input())
        ls[w] = s
    sp = input()
    p = 0
    for i in ls:
        for j in range(len(sp)-len(i)+1):
            if sp[j:j+len(i)] == i:
                p += ls[i]
    print(p)
