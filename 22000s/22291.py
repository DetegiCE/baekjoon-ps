def isPrime(n):
    if n == 2 or n == 3: return True
    if n % 2 == 0 or n < 2: return False
    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            return False
    return True

def isSquare(n):
    if n < 0:
        return False
    a = int(n**0.5)
    if a * a == n:
        return True
    return False

def P2(A):
    n = len(A)
    s = 0
    for i in range(n):
        if isSquare(A[i]) and isPrime(i):
            s += A[i]
    return s
