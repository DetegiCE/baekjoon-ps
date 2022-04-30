n = int(input())
flag = 0
for i in range(2, n+1):
    for j in range(1, 20):
        if i ** j == n:
            print(i)
            flag = 1
            break
        if i ** j > n:
            break
    if flag == 1:
        break