for _ in range(int(input())):
    n = int(input())
    if n == 1:
        print(1)
        continue
    c2 = 0
    c3 = 0
    c5 = 0
    c7 = 0
    while n % 2 == 0:
        c2 += 1
        n //= 2
    while n % 3 == 0:
        c3 += 1
        n //= 3
    while n % 5 == 0:
        c5 += 1
        n //= 5
    while n % 7 == 0:
        c7 += 1
        n //= 7
    if n > 1:
        print(-1)
        continue
    tc = c5 + c7 + c3 // 2 + c2 // 3
    c3 %= 2
    c2 %= 3
    if c3 == 0 and c2 == 1: tc+=1
    if c3 == 0 and c2 == 2: tc+=1
    if c3 == 1 and c2 == 0: tc+=1
    if c3 == 1 and c2 == 1: tc+=1
    if c3 == 1 and c2 == 2: tc+=2
    print(tc)