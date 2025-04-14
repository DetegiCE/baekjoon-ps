n = int(input())
sc = 0
for _ in range(n):
    s, a, t, m = map(float, input().split())
    sc += s*(a+1)/a*(t+m)/t/4
p = int(input())
rnk = 1
for _ in range(p):
    r = float(input())
    if r > sc: rnk += 1
if rnk*100/(p+1) <= 15:
    print('The total score of Younghoon "The God" is %.02f.' % sc)
else:
    print('The total score of Younghoon is %.02f.' % sc)