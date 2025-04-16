def chk(a):
    i = 2
    while i * i < a:
        if a % (i * i) == 0: return False
        i += 1
    return True

n = int(input())
for i in range(2, n):
    if chk(n*i):
        print(i)
        exit(0)