import math
n,k=map(int,input().split())
for i in range(-100000, 100001):
    t = i * i + 4 * k * n
    if t >= 0:
        d = math.trunc(math.sqrt(t))
        if d * d != t:
            continue
        if (d-i) % (k*2) == 0:
            p = (d-i) // (k * 2)
            q = n // p
            if p > 1 and q > 1 and p*q == n:
                print(f'{min(p,q)} * {max(p,q)}')
                break
        if (d+i) % (k*2) == 0:
            p = (d+i) // (k * 2)
            q = n // p
            if p > 1 and q > 1 and p*q == n:
                print(f'{min(p,q)} * {max(p,q)}')
                break
    

# kp - 1e5 <= q <= kp + 1e5
# q-kp = X => -1e5 <= X <= 1e5
# q = kp + X
# n = pq = p (kp+X) => kp^2 + Xp - n = 0
#                 D = X^2 + 4kn
