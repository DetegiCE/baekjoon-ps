from sys import stdin
input = stdin.readline

def check(m):
    if not prime[m]:
        return False
    chk = []
    for i in range(501):
        chk.append(False)
    s = 0
    while True:
        if m == 1:
            return True
        s = 0
        while m > 0:
            s += (m%10) ** 2
            m //= 10
        if chk[s]:
            return False
        chk[s] = True
        m = s

prime = []
for i in range(10001):
    prime.append(True)
prime[1] = False
for i in range(2, 10001):
    if prime[i]:
        for j in range(2, 10001):
            if i*j > 10000:
                break
            prime[i*j] = False
            
q = int(input())
for i in range(q):
    t, m = map(int, input().split())
    if check(m):
        print(t, m, "YES")
    else:
        print(t, m, "NO")
