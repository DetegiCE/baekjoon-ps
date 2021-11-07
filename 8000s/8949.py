a, b = map(lambda x: x[::-1], input().split())
ans = list()
for i in range(min(len(a), len(b))):
    ans.append(ord(a[i]) + ord(b[i]) - 96)
if len(a) > len(b):
    for i in range(len(b), len(a)):
        ans.append(ord(a[i]) - 48)
else:
    for i in range(len(a), len(b)):
        ans.append(ord(b[i]) - 48)
for e in ans[::-1]:
    print(e, end='')
    
