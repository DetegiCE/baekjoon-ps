def convb(n, b):
    dig = '0123456789ABCDEF'
    if n == 0:
        return '0'
    res = []
    while n > 0:
        res.append(dig[n % b])
        n //= b
    return ''.join(res[::-1])

def f(line):
    a = line.split()
    n, fr, to = a
    fr, to = int(fr), int(to)
    try:
        num = int(n, fr)
        conv = convb(num, to)
    except:
        print('  ERROR')
        return

    if len(conv) > 7:
        print('  ERROR')
    else:
        print(conv.rjust(7))

while True:
    try:
        a = input()
        f(a)
    except:
        break