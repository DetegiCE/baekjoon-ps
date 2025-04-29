n = int(input())
s = set()
for i in range(1, n+1):
    for j in range(i+1, i+(n+1)//2):
        if (i, j) not in s:
            s.add((i, j))
            print(i, (j-1)%n+1)