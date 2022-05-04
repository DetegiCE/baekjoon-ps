def f(n):
    if n == 99: 
        return 0
    m = n
    sum = 0
    cnt = 0
    while n > 0:
        n //= 10
        cnt += 1
    for i in range(3, cnt):
        sum += 81 * i
    # print(sum)
    for i in range(0, 10):
        for j in range(cnt):
            for k in range(10):
                a = str(i) * cnt
                if k == i:
                    continue
                a = a[:j] + str(k) + a[j+1:]
                if a[0] == '0': 
                    continue
                # print(a)
                if int(a) <= m:
                    sum += 1
    return sum

if __name__ == '__main__':
    x, y = map(int, input().split())
    # print(f(y), f(x-1))
    ans = f(y) - f(x-1)
    print(ans)
    # print(f(999))