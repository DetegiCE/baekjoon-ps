def isprime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n == 1:
        return False
    for i in range(3, int(n**0.5)+1, 2):
        if n % i == 0:
            return False
    return True

f = '012XX59X86'
n = input()
m = ''.join(list(map(lambda x: f[ord(x)-48] ,list(n[::-1]))))
if 'X' in m:
    print('no')
else:
    n = int(n)
    m = int(m)
    if isprime(n) and isprime(m):
        print('yes')
    else:
        print('no')
