def baseconv(n, k):
    b = '0123456789abcdefghijklmnopqrstuvwxyz'
    r = []
    while n > 0:
        r.append(b[n % k])
        n //= k
    return ''.join(r)[::-1]

def checkconv(a, k):
    b = '0123456789abcdefghijklmnopqrstuvwxyz'
    m = b[:k]
    for i in m:
        if i not in a:
            return False
    return True
    

def sol():
    n, k = map(int, input().split())
    a = baseconv(n, k).lstrip('0')
    if a == '':
        a = '0'
    print(f'Base-{k} representation of {n} is {a};', end=' ')
    if checkconv(a, k):
        print('contains all digits.')
    else:
        print('does not contain all digits.')

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        sol()