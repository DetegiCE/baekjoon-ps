n = int(input())
x0, y0, e0 = map(int, input().split())
wifi = []
e = 0
mx = 0
for _ in range(n):
    x, y, ei = map(int, input().split())
    wifi.append([x, y, ei])
for i in range(n):
    s = max(0, e0 - abs(x0-wifi[i][0]) - abs(y0-wifi[i][1]))
    for j in range(n):
        s -= max(0, wifi[j][2]-abs(wifi[i][0]-wifi[j][0])-abs(wifi[i][1]-wifi[j][1]))
    mx = max(mx, s)
if mx <= 0:
    print('IMPOSSIBLE')
else: print(mx)
