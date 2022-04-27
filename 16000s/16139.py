import sys
s = sys.stdin.readline().strip('\n')
cnt = [[0 for _ in range(26)] for _ in range(len(s))]
cnt[0][ord(s[0]) - ord('a')] = 1
for i in range(1, len(s)):
    cnt[i][ord(s[i]) - ord('a')] = cnt[i-1][ord(s[i]) - ord('a')] + 1
    for j in range(26):
        if j == ord(s[i]) - ord('a'): continue
        cnt[i][j] = cnt[i-1][j]
n = int(sys.stdin.readline())
for _ in range(n):
    a, l, r = sys.stdin.readline().split()
    l = int(l)
    r = int(r)
    if l == 0:
        sys.stdout.write(str(cnt[r][ord(a[0]) - ord('a')]) + '\n')
    else:
        sys.stdout.write(str(cnt[r][ord(a[0]) - ord('a')] - cnt[l-1][ord(a[0]) - ord('a')]) + '\n')