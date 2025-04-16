h1, m1 = map(int, input().split(':'))
h2, m2 = map(int, input().split(':'))
t1 = h1 * 60 + m1
t2 = h2 * 60 + m2
if t1 > t2: t2 += 1440
d = t2 - t1
print(d // 60 + d % 60)