a, b = map(int, input().split())
x, y = map(int, input().split())
if a > b:
    a, b = b, a
aq = a//x
bq = (b+x)//x
if aq > bq:
    aq, bq = bq, aq
if not(0 <= y < abs(x)):
    print('Unknwon Number')
    exit(0)
c1, c2 = -1e10, -1e10
for i in range(aq, bq+1):
    c = i*x+y
    if a <= c <= b:
        if c1 == -1e10:
            c1 = c
        else:
            print('Unknwon Number')
            exit(0)
if c1 == -1e10:
    print('Unknwon Number')
else:
    print(c1)
