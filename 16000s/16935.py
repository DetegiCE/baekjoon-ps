n = m = r = c = -1
a = []

def vflip():
    global a
    b = []
    for i in range(len(a)-1, -1, -1):
        c = []
        for j in range(len(a[0])):
            c.append(a[i][j])
        b.append(c)
    a = b

def hflip():
    global a
    b = []
    for i in range(len(a)):
        c = []
        for j in range(len(a[0])-1, -1, -1):
            c.append(a[i][j])
        b.append(c)
    a = b
        
def l90():
    global a
    b = []
    for j in range(len(a[0])):
        c = []
        for i in range(len(a)-1, -1, -1):
            c.append(a[i][j])
        b.append(c)
    a = b
        
def r90():
    global a
    b = []
    for j in range(len(a[0])-1, -1, -1):
        c = []
        for i in range(len(a)):
            c.append(a[i][j])
        b.append(c)
    a = b
        
def rot1():
    global a
    b = []
    for i in range(len(a)//2, len(a)):
        c = []
        for j in range(len(a[0])//2):
            c.append(a[i][j])
        for j in range(len(a[0])//2):
            c.append(a[i-len(a)//2][j])
        b.append(c)
    for i in range(len(a)//2, len(a)):
        c = []
        for j in range(len(a[0])//2, len(a[0])):
            c.append(a[i][j])
        for j in range(len(a[0])//2, len(a[0])):
            c.append(a[i-len(a)//2][j])
        b.append(c)
    a = b

def rot2():
    global a
    b = []
    for i in range(len(a)//2):
        tj = 0
        c = []
        for j in range(len(a[0])//2, len(a[0])):
            c.append(a[i][j])
        for j in range(len(a[0])//2, len(a[0])):
            c.append(a[i+len(a)//2][j])
        b.append(c)
    for i in range(len(a)//2):
        c = []
        for j in range(len(a[0])//2):
            c.append(a[i][j])
        for j in range(len(a[0])//2):
            c.append(a[i+len(a)//2][j])
        b.append(c)
    a = b
        
if __name__ == '__main__':
    n, m, r = map(int,input().split())
    for i in range(n):
        a.append(list(map(int,input().split())))
    d = list(map(int,input().split()))
    for e in d:
        if e == 1:
            vflip()
        elif e == 2:
            hflip()
        elif e == 3:
            l90()
        elif e == 4:
            r90()
        elif e == 5:
            rot1()
        else:
            rot2()
    for i in range(len(a)):
        for j in range(len(a[0])):
            print(a[i][j], end=' ')
        print()