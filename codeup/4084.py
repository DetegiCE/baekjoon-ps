s = input()
if not(s[0] == 'O' and s[-1] == 'X'):
    print('data error')
    quit()
s = s[1:-1]
s = s[::-1]
for i in range(0, len(s), 2):
    a = int(s[i:i+2], 16)
    print(chr(a), end='')