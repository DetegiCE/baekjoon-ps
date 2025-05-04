s = input()
p = input()
if s == p:
    print('Yes')
    exit(0)
elif len(s) == len(p) + 1:
    for i in range(10):
        if s == p + str(i) or s == str(i) + p:
            print('Yes')
            exit(0)
else:
    t = ''
    for i in s:
        if 97 <= ord(i) <= 122:
            t += chr(ord(i) - 32)
        elif 65 <= ord(i) <= 90:
            t += chr(ord(i) + 32)
        else:
            t += i
    if t == p:
        print('Yes')
        exit(0)
print('No')