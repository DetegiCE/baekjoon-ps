def getmin2(d):
    b = [(0, 1), (0, 2), (0, 3), (0, 4), (1, 3), (3, 4), (2, 4), (2, 1), (5, 1), (5, 2), (5, 3), (5, 4)]
    mnv = 999
    for c in b:
        mnv = min(mnv, d[c[0]] + d[c[1]])
    return mnv
    
def getmin3(d):
    b = [(0, 1, 3), (0, 3, 4), (0, 2, 4), (0, 1, 2), (5, 1, 3), (5, 3, 4), (5, 2, 4), (5, 2, 1)]
    mnv = 999
    for c in b:
        mnv = min(mnv, d[c[0]] + d[c[1]] + d[c[2]])
    return mnv

n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(sum(a)-max(a))
    exit(0)
min1 = min(a)
min2 = getmin2(a)
min3 = getmin3(a)
print(min3*4 + min2*((n-2)*4+(n-1)*4) + min1*((n-2)**2+((n-2)*(n-1)*4)))
