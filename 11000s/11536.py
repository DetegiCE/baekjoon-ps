a = []
m = 0
n = int(input())
for _ in range(n):
    a.append(input())
if a[0] == a[1]:
    print('NEITHER')
    quit()
if a[0] < a[1]:
    m = 1
else:
    m = -1
for i in range(1, n-1):
    if a[i] < a[i+1]:
        if m == -1:
            print('NEITHER')
            quit()
    elif a[i] > a[i+1]:
        if m == 1:
            print('NEITHER')
            quit()
if m == 1: print('INCREASING')
else: print('DECREASING')