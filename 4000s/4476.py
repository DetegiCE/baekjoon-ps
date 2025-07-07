def r90(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = j
        nj = n - 1 - i
        res[ni] = nj
    return res

def r180(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = n - 1 - i
        nj = n - 1 - j
        res[ni] = nj
    return res

def r270(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = n - 1 - j
        nj = i
        res[ni] = nj
    return res

def rv(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        res[i] = n - 1 - j
    return res

def rh(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = n - 1 - i
        res[ni] = j
    return res

def rd(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = j
        nj = i
        res[ni] = nj
    return res

def rad(pos, n):
    res = [0] * n
    for i in range(n):
        j = pos[i]
        ni = n - 1 - j
        nj = n - 1 - i
        res[ni] = nj
    return res

def pr(pos):
    return ''.join(f"{i:3d}" for i in pos)

while True:
    line = input()
    if not line:
        continue
        
    nums = list(map(int, line.split()))
    n = nums[0]
    
    if n == 0:
        break
        
    pos = nums[1:]
    
    anss = [
        pos,
        r90(pos, n),
        r180(pos, n),
        r270(pos, n),
        rv(pos, n),
        rad(pos, n),
        rh(pos, n),
        rd(pos, n),
    ]
    
    for i in anss:
        print(pr(i))
    print()
