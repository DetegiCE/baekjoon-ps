for _ in range(int(input())):
    n = int(input())
    n-=1
    print((2**(n-2)*n*(5+n))/(2**n))