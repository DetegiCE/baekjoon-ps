def sol(n):
    mxv = n
    while n > 1:
        if n % 2 == 0:
            n //= 2
        else:
            n = 3 * n + 1
        mxv = max(mxv, n)
    print(mxv)

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        sol(n)