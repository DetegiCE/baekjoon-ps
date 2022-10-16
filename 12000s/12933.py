a = input()
lev = [0,0,0,0,0]
mx = 0
cur = 0
for i in a:
    if i == 'q':
        lev[0] += 1
        cur += 1
    if i == 'u':
        if lev[0] > 0:
            lev[0] -= 1
            lev[1] += 1
        else:
            print(-1)
            quit()
    if i == 'a':
        if lev[1] > 0:
            lev[1] -= 1
            lev[2] += 1
        else:
            print(-1)
            quit()
    if i == 'c':
        if lev[2] > 0:
            lev[2] -= 1
            lev[3] += 1
        else:
            print(-1)
            quit()
    if i == 'k':
        if lev[3] > 0:
            lev[3] -= 1
            cur -= 1
        else:
            print(-1)
            quit()
    mx = max(mx, cur)
for i in lev:
    if i > 0:
        print(-1)
        quit()
print(mx)
            