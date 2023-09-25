from math import comb
while True:
    a, b = map(int, input().split())
    if a == -1:
        break
    print(a,'+',b,sep='',end='')
    if a+b != comb(a+b, a): print('!',end='')
    print('=',a+b,sep='')        
