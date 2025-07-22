s = [0] + list(map(int, input().split()))
t = sum(s)
if t % 2 == 1:
    print('NO')
    exit(0)
a = t//4 - s[5] - s[10]
b = t//4 - s[2] - s[10]
c = t//4 - s[1] - s[10]
d = t//4 - s[1] - s[9]
e = t//4 - s[1] - s[8]
if a + b == s[1] and a + c == s[2] and a + d == s[3] and a + e == s[4] and \
    b + c == s[5] and b + d == s[6] and b + e == s[7] and c + d == s[8] and \
    c + e == s[9] and d + e == s[10] and a >= 0 and b >= 0 and c >= 0 and d >= 0 and e >= 0:
    print('YES')
else:
    print('NO')