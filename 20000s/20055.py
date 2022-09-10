if __name__ == '__main__':
    n, k = map(int,input().split())
    a = [0]
    a.extend(list(map(int,input().split())))
    robotpos = []
    onpos = 1
    enpos = n
    for lev in range(1, 1000001):
        # print(lev, k, robotpos, onpos, enpos)
        if onpos == 1:
            onpos = 2 * n
        else:
            onpos -= 1
        if enpos == 1:
            enpos = 2 * n
        else:
            enpos -= 1
        try:
            robotpos.remove(1 if enpos == 2*n else enpos+1)
        except:
            pass
        for i in range(len(robotpos)):
            if robotpos[i] == enpos:
                if enpos == 2 * n:
                    robotpos[i] = 1
                else:
                    robotpos[i] += 1
                continue
            if robotpos[i] == 2 * n and (1 not in robotpos) and a[1] > 0:
                robotpos[i] = 1
                a[1] -= 1
                if a[1] == 0:
                    k -= 1
            elif robotpos[i] != 2 * n and (robotpos[i]+1 not in robotpos) and a[robotpos[i]+1] > 0:
                robotpos[i] += 1
                a[robotpos[i]] -= 1
                if a[robotpos[i]] == 0:
                    k -= 1
        try:
            robotpos.remove(1 if enpos == 2*n else enpos+1)
        except:
            pass
        if a[onpos] > 0:
            robotpos.append(onpos)
            a[onpos] -= 1
            if a[onpos] == 0:
                k -= 1
        if k <= 0:
            print(lev)
            break
