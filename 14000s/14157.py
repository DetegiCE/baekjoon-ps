import math

def f(s, a):
    for fx in range(s + 1):
        for fy in range(s + 1):
            if (fx, fy) in a:
                continue
            mx = 0
            for hx, hy in a:
                dst = math.sqrt((fx - hx) ** 2 + (fy - hy) ** 2)
                mx = max(mx, dst)
            l = mx
            if  l <= fx <= s - l and l <= fy <= s - l:
                return (fx, fy)
    
    return (-1, -1)

n = int(input())

for _ in range(n):
    s, h = map(int, input().split())
    a = []
    
    for _ in range(h):
        x, y = map(int, input().split())
        a.append((x, y))
    
    b = f(s, a)
    print(b[0], b[1])
