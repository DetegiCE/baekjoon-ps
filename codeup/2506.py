a = float(input())
if a == 0.0:
    print('0/1')
    quit()
if a == 100.0:
    print('1/1')
    quit()
for i in range(2, 1001):
    for j in range(1, i):
        #print(i, j, end='=')
        s = '%.10f' % (j/i)
        #print(s, end='-')
        snd = s.split('.')[1][3]
        #print(snd, end='-')
        frt = float(s.split('.')[1][0:2] + '.' + s.split('.')[1][2])
        #print(frt)
        if 5 <= int(snd):
            frt += 0.1
        if str(a) == '%.1f' % frt:
            print(str(j)+'/'+str(i))
            quit()