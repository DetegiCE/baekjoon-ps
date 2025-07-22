from sys import stdin
input = stdin.readline
t = int(input().strip())
for _ in range(t):
    p = int(input().rstrip())
    a = set([input().rstrip() for _ in range(p)])
    l = int(input().rstrip())
    b = ''
    for i in range(l):
        b += input().lower().rstrip()+' '
    c = ['']
    for i in b:
        if 97 <= ord(i) <= 122:
            c[-1] += i
        elif c[-1] != '':
            c.append('')
    if c[-1] == '':
        c.pop()
    cnt = 0
    for i in c:
        if i in a:
            cnt += 1
    if cnt*4 >= 3*len(c):
        print('It\'s a hit!')
    else:
        print('Delete immediately!')