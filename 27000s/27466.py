n, m = map(int, input().split())
a = input()[::-1]
ans = []
vowel = 'AEIOU'
step = 0
for i in a:
    if step == 0:
        if i not in vowel:
            ans.append(i)
            step += 1
    elif step == 1 or step == 2:
        if i == 'A':
            ans.append(i)
            step += 1
    else:
        ans.append(i)
if len(ans) < m:
    print('NO')
else:
    print('YES')
    print(''.join(ans[:m])[::-1])
