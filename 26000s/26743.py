d = {}
for _ in range(int(input())):
    a = input()
    acnt = 0
    score = 0
    for i in a:
        if i in '23456789':
            score += int(i)
        if i in 'TJKQ':
            score += 10
        if i == 'A':
            acnt += 1
    if score > 21:
        continue
    else:
        if acnt > 0:
            ts = -1
            for i in range(acnt+1):
                tmp = score + 11 * i + (acnt - i)
                if tmp > 21:
                    break
                ts = tmp
            if ts == -1:
                continue
            else:
                d[_+1] = ts
        else:
            d[_+1] = score
if len(d) == 0:
    print(0)
    exit(0)
vl = list(d.values())
mx = max(vl)
print(vl.count(mx))
for i in d:
    if d[i] == mx:
        print(i, end=' ')
