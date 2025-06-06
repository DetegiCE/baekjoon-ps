from sys import stdin
input = stdin.readline
x1, y1, x2, y2, x3, y3 = map(int, input().split())
q = int(input())
for _ in range(q):
    x, y, t1, t2, t3 = map(int, input().split())
    d1 = abs(x1-x) + abs(y1-y)
    d2 = abs(x2-x) + abs(y2-y)
    d3 = abs(x3-x) + abs(y3-y)
    s1 = d1 if d1 % t1 == 0 else (t1 * (d1//t1+1))
    s2 = d2 if d2 % t2 == 0 else (t2 * (d2//t2+1))
    s3 = d3 if d3 % t3 == 0 else (t3 * (d3//t3+1))
    #print(d1, d2, d3)
    #print(s1, s2, s3)
    print(min(s1, s2, s3))