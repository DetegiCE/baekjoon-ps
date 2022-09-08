for _ in range(int(input())):
    print(f'Data Set {_+1}:')
    n = int(input())
    s = []
    for i in range(n-1):
        s.append(int(input()))
    nm = []
    for i in range(n):
        nm.append(input())
    st = input()
    stpos = nm.index(st)
    en = input()
    enpos = nm.index(en)
    print(s[abs(enpos-stpos)-1])
    print()