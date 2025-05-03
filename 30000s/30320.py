rt, rj, st, sj = input().split()
rt, rj = int(rt), int(rj)
st, sj = round(float(st)*100), round(float(sj)*100)
if (rt-1) * sj == (rj-1) * st:
    print('SAME')
elif (rt-1) * sj < (rj-1) * st:
    print('TAOYUAN')
else:
    print('JAKARTA')