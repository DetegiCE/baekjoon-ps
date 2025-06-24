from itertools import permutations as perm

def l2n(n):
    return ord(n) - 64

def f(v, w, x, y, z):
    return v - w**2 + x**3 - y**4 + z**5

while True:
    line = input()
    if line == '0 END':
        break
    s, l = line.split()
    t = int(s)
    mx = None

    for c in perm(l, 5):
        v, w, x, y, z = map(l2n, c)
        a = f(v, w, x, y, z)
        if a == t:
            d = ''.join(c)
            if (mx is None) or (d > mx):
                mx = d
    if mx: print(mx)
    else: print("no solution")
