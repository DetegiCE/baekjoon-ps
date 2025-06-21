z = int(input())
for _ in range(z):
    x, y = map(float, input().split())
    if round(x+y, 4) < round(x*y, 4): print('TAK')
    else: print('NIE')