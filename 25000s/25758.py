n = int(input())
a = input().split()
f = dict()
s = dict()
for i in range(26):
    f[i] = set()
    s[i] = set()
c = 0
for i in a:
    f[ord(i[0])-65].add(c)
    s[ord(i[1])-65].add(c)
    c += 1
ans = []
for i in range(26):
    flg = 0
    for j in range(i+1):
        for k in f[i]:
            if k in s[j] and len(s[j]) > 1:
                ans.append(i)
                flg = 1
                break
            if k not in s[j] and len(s[j]) > 0:
                ans.append(i)
                flg = 1
                break
        if flg == 0:
            for k in s[i]:
                if k in f[j] and len(f[j]) > 1:
                    ans.append(i)
                    flg = 1
                    break
                if k not in f[j] and len(f[j]) > 0:
                    ans.append(i)
                    flg = 1
                    break
        if flg == 1:
            break

print(len(ans))
for i in ans:
    print(chr(i+65), end=' ')