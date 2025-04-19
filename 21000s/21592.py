n = int(input())
if n == 1:
    print(len(input()))
    exit(0)
a = [input() for _ in range(n)]
a.sort(key=lambda x: len(x))
s = []
for i in range(len(a[0])):
    for j in range(i+1, len(a[0])+1):
        s.append(a[0][i:j])
mx = 0
for i in s:
    f = 0
    for j in a[1:]:
        if i not in j:
            f = 1
            break
    if f == 0:
        mx = max(mx, len(i))
print(mx)