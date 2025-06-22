cnt = 1
a, b, c = map(int, input().split())
for i in range(2015, a):
    cnt += 4
if b >= 3: cnt += 1
if b >= 6: cnt += 1
if b >= 9: cnt += 1
if b >= 12: cnt += 1
print(cnt)