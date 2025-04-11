n = int(input())
a = list(map(int, input().split()))
ans = 0
b = 100000
for i in a:
    if b >= i: b = i
    else: ans = max(ans, i - b)
print(ans)