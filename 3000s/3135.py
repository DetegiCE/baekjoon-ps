a, b = map(int, input().split())
n = int(input())
mn = abs(a-b)
for i in range(n):
    c = int(input())
    mn = min(mn, abs(c-b)+1)
print(mn)