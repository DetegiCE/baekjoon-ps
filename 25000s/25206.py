sum1 = 0
sum2 = 0
sco = ['F', '', 'D0', 'D+', 'C0', 'C+', 'B0', 'B+', 'A0', 'A+']
for _ in range(20):
    a, b, c = input().split()
    b = float(b)
    if c == 'P': continue
    else:
        sum1 += sco.index(c) * 0.5 * b
        sum2 += b
if sum2 == 0:
    print(0)
else:
    print(sum1/sum2)