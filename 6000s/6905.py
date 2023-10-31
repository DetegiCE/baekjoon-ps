pos = 1
lad = {9:34, 40:64, 67:86}
snk = {99:77, 90:48, 54:19}
while True:
    try:
        a = int(input())
        if a == 0:
            print('You Quit!')
            exit(0)
        pos += a
        if pos == 100:
            print('You are now on square 100')
            print('You Win!')
            exit(0)
        if pos > 100:
            pos -= a
        if pos in lad:
            pos = lad[pos]
        if pos in snk:
            pos = snk[pos]
        print(f'You are now on square {pos}')
    except:
        break
