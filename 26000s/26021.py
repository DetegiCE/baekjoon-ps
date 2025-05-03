n, k = map(int, input().split())
s = input()
if s[0] == 'R':
    k -= 1
for i in range(1, n):
    if s[i] == s[i-1]: k -= 1
print(max(0, k))