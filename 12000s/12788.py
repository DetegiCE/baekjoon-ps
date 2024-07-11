n = int(input())
m, k = map(int, input().split())
a = reversed(sorted(list(map(int, input().split()))))
m *= k
c = 0
s = 0
for i in a:
    s += i
    c += 1
    if s >= m:
        break
if s < m:
    print('STRESS')
else:
    print(c)
