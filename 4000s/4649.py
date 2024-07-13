while True:
    a = input()
    if a == '0':
        break
    n, m = a.split()
    n = int(n)
    cnt = 0
    s = set()
    for i in m:
        if i not in s and len(s) < n:
            s.add(i)
        elif i in s:
            s.remove(i)
        else:
            cnt += 1
    if cnt == 0:
        print('All customers tanned successfully.')
    else:
        print(f'{cnt//2} customer(s) walked away.')
