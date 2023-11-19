from sys import stdin
input = stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    b = a[::2] + a[1::2][::-1] + [a[0]]
    mx = 0
    # print(b)
    for i in range(n):
        mx = max(mx, abs(b[i] - b[i+1]))
    print(mx)
    
