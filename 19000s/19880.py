s = input()
ans = len(s) // 2
for i in range(1, len(s) // 2):
    if s[i] == '0':
        ans -= 1
if s[0] == '0':
    print(0)
    exit(0)
if len(s) % 2 == 0:
    if s[len(s) // 2] == '0':
        ans -= 1
    else:
        chk = False
        a = s[:len(s)//2]
        b = s[len(s)//2:]
        for i in range(len(s) // 2):
            if a[i] > b[i]:
                chk = True
                break
            elif a[i] < b[i]:
                break
        if chk:
            ans -= 1
else:
    if s[len(s)//2] == '0':
        ans -= 1
print(ans)