n, d = input().split()
n = int(n)
if len(d) > n:
    print('No solution')
else:
    print(d + '0' * (n-len(d)))