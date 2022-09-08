n = m = -1
s = 0
a = []

def area(y: int, x: int) -> int:
    ts = 2
    ts += max(0, a[y][x] - a[y-1][x])
    ts += max(0, a[y][x] - a[y+1][x])
    ts += max(0, a[y][x] - a[y][x-1])
    ts += max(0, a[y][x] - a[y][x+1])
    return ts

if __name__ == '__main__':
    n, m = map(int,input().split())
    a.append([0] * (m+2))
    for i in range(1, n+1):
        if m == 1:
            a.append([0, int(input()), 0])
        else:
            b = [0]
            b.extend(list(map(int,input().split())))
            b.append(0)
            a.append(b)
    a.append([0] * (m+2))
        
    for i in range(1, n+1):
        for j in range(1, m+1):
            s += area(i, j)
    print(s)