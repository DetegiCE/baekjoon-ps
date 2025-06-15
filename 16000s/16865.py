s, n, m = map(int, input().split())
a = []
while True:
    try:
        a += list(map(int, input().split()))
    except:
        break
p_cnt = 0
v_cnt = 0
for i in range(n-1, s-n+1):
    inc_cnt = 0
    dec_cnt = 0
    for j in range(i-n+1, i):
        if j < 0 or j+1 >= s: continue
        if a[j] < a[j+1]:
            inc_cnt += 1
    for j in range(i, i+n-1):
        if j < 0 or j+1 >= s: continue
        if a[j] > a[j+1]:
            dec_cnt += 1
    if inc_cnt == n-1 and dec_cnt == n-1:
        p_cnt += 1
for i in range(m-1, s-m+1):
    dec_cnt = 0
    inc_cnt = 0
    for j in range(i-m+1, i):
        if j < 0 or j+1 >= s: continue
        if a[j] > a[j+1]:
            dec_cnt += 1
    for j in range(i, i+m-1):
        if j < 0 or j+1 >= s: continue
        if a[j] < a[j+1]:
            inc_cnt += 1
    if inc_cnt == m-1 and dec_cnt == m-1:
        v_cnt += 1
print(p_cnt, v_cnt)