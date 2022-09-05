def gcd(a: int, b: int) -> int:
    if b > 0:
        return gcd(b, a%b)
    else:
        return a

def sol(d):
    s = d.split('.')[1]
    if '(' not in s:
        sup = int(s)
        sdn = int(10**len(s))
        g = gcd(sup, sdn)
        print(str(sup//g)+'/'+str(sdn//g))
    else:
        pst = s.find('(')
        pen = s.find(')')
        ins = s[pst+1:pen]
        sup = int(s.replace('(','').replace(')',''))-(0 if pst == 0 else int(s[:pst]))
        sdn = int('9'*len(ins)+'0'*(len(s)-len(ins)-2))
        g = gcd(sup, sdn)
        print(str(sup//g)+'/'+str(sdn//g))

if __name__ == '__main__':
    for _ in range(int(input())):
        sol(input())