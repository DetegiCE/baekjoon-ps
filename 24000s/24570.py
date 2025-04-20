a = input()
m = 0
for i in a:
    if 65 <= ord(i) <= 90:
        if m == 1:
            print()
            m = 0
        print(i, end='')
    elif i == '+':
        print(' tighten ', end='')
    elif i == '-':
        print(' loosen ', end='')
    else:
        m = 1
        print(i, end='')