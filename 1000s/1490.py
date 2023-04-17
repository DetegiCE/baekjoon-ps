def chk(num, r):
    for i in r:
        if i == '0':
            continue
        if num % int(i) != 0:
            return False
    return True

n = input()
if chk(int(n), n):
    print(n)
else:
    dig = 1
    while True:
        for i in range(0, 10**dig):
            if chk(int(n+(str(i).zfill(dig))), n):
                print(n+(str(i).zfill(dig)))
                exit(0)
        dig += 1
