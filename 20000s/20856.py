a, b, c, d = map(int, input().split())
cnt = d + c + b // 2
a = max(0, a-c)
b %= 2
if b == 0: cnt += (a + 3) // 4
else: cnt += (a + 5) // 4
print(cnt)