from bisect import bisect_left, bisect_right
p = [False] * 1002
primes = [1, 2]
p[2] = True
for i in range(3, 1002, 2):
    if p[i]:
        continue
    primes.append(i)
    for j in range(i*i, 1002, i*2):
        p[j] = True

while True:
    try:
        n, c = map(int, input().split())
        print(f'{n} {c}: ', end='')
        l = bisect_left(primes, n)
        k = bisect_right(primes, n)
        if k % 2 == 0:
            c = c * 2
        else: c = c * 2 - 1
        if c > k: c = k
        t = (k-c) // 2
        for i in range(t, k-t):
            print(primes[i], end=' ')
        print('\n')
    except:
        break
