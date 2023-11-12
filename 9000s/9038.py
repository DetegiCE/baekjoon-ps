t = int(input())
for _ in range(t):
    n = int(input())
    a = input().split()
    line = 1
    lpos = len(a[0])
    for i in range(1, len(a)):
        if lpos + 1 + len(a[i]) <= n:
            lpos += (len(a[i]) + 1)
        else:
            line += 1
            lpos = len(a[i])
    print(line)
