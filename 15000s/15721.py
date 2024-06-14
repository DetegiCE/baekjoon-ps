a = int(input())
t = int(input())
b = int(input())

s = ''
for i in range(1500):
    s += '0101' + '0' * (i+2) + '1' * (i+2)

zc = 0
oc = 0
for i in range(len(s)):
    if s[i] == '0': zc += 1
    if s[i] == '1': oc += 1
    if b == 0 and zc == t:
        print(i % a)
        break
    if b == 1 and oc == t:
        print(i % a)
        break
