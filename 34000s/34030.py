n = int(input())
a = list(map(int, input().split()))
co = True
ce = True
for i in range(1, n):
    if a[i-1] > a[i]:
        if (a[i-1]+a[i]) % 2 == 0: co = False
        else: ce = False
if co: print('So Lucky')
else: print('Unlucky')
if ce: print('So Lucky')
else: print('Unlucky')
    