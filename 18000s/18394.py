import sys

def r90(s):
    hh = len(s)
    ww = len(s[0])
    ss = []
    for i in range(ww):
        sstt = ''
        for j in range(hh-1, -1, -1):
            #print(i, j)
            sstt += s[j][i]
        ss.append(sstt)
    return ss

def r180(s):
    s = r90(s)
    return r90(s)

def r270(s):
    s = r180(s)
    return r90(s)

def chk(s, t):
    if len(s) != len(t): return False
    if len(s[0]) != len(t[0]): return False
    for i in range(len(s)):
        for j in range(len(s[0])):
            if s[i][j] != t[i][j]:
                return False
    return True
    
def chkrt(s, t):
    return chk(s, t) or chk(s, r90(t)) or chk(s, r180(t)) or chk(s, r270(t))

l,w,h=map(int,sys.stdin.readline().split())
sames=[]
vis=[0 for i in range(l)]
names = [0 for i in range(l)]
pics = [0 for i in range(l)]
for i in range(l):
    names[i] = sys.stdin.readline().rstrip()
    t=sys.stdin.readline().rstrip()
    s=[]
    if len(t) == w:
        s=[0 for i in range(h)]
        s[0]=t
    else:
        s=[0 for i in range(w)]
        s[0]=t
    #print(f'[{s}], {len(s[0])}')
    if len(s[0]) == w:
        for j in range(h-1):
            s[j+1]=sys.stdin.readline().rstrip()
    else:
        for j in range(w-1):
            s[j+1]=sys.stdin.readline().rstrip()
    pics[i] = s
    wwww=sys.stdin.readline()
for i in range(l):
    for j in range(i+1, l):
        if chkrt(pics[i], pics[j]):
            #print(i, j)
            vis[i]=vis[j]=1
for i in range(l):
    if vis[i] == 1:
        sames.append(names[i])
sames.sort()
for i in sames:
    print(i)