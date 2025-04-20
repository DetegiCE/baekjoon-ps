n = int(input())
for i in range(n):
    a = int(input())
    for j in range(int(a**0.5), 0, -1):
        if a % j == 0:
            p = j
            q = a // j
            if 2 * p >= q:
                print(1)
            else:
                print(0)
            break