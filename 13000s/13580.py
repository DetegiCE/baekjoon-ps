a = sorted(list(map(int, input().split())))
if not a[0]-a[1] or not a[1]-a[2] or not a[0]-a[2] or a[0]+a[1]==a[2]: print('S')
else: print('N')
