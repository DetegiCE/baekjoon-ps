n, a, b = map(int, input().split())
s = input()
m = 1
while b > 0:
    if b % 2 == 1:
        m *= a
        m %= 26
    a *= a
    a %= 26
    b //= 2

for i in range(len(s)):
    if s[i] == ' ':
        print(' ', end='')
        continue
    print(chr(65+(ord(s[i])-65-m+26)%26), end='')