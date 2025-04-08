n, q = map(int, input().split())
s = list(input())
for _ in range(q):
    a, l, r = map(int, input().split())
    l -= 1
    r -= 1
    if a == 1:
        c = 1
        for i in range(l+1, r+1):
            if s[i] != s[i-1]:
                c += 1
        print(c)
    else:
        for i in range(l, r+1):
            s[i] = chr((ord(s[i]) - 64) % 26 + 65)
