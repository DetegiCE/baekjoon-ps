c = ['', 'January', 'February', 'March', 'April', 'May', 'June',
     'July', 'August', 'September', 'October', 'November', 'December']
while True:
    a, b = input().split()
    if a == '0':
        break
    a = int(a)
    b = c.index(b)
    if b == 8 and a == 4:
        print('Happy birthday')
    elif b == 2 and a == 29:
        print('Unlucky')
    elif b < 8 or (b == 8 and a < 4):
        print('Yes')
    else:
        print('No')
