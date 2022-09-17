cnt = [0] * 10001
p = [False] * 1000001

def primes():
    for i in range(3, 999984, 2):
        if not p[i]:
            for j in range(i*2, 1000000, i):
                p[j] = True

def sol(n):
    if n == 4:
        print(1)
        return
    c = 0
    for i in range(3, n//2+1, 2):
        if not(p[i] or p[n-i]):
            c += 1
    print(c)

if __name__ == '__main__':
    primes()
    for _ in range(int(input())):
        sol(int(input()))