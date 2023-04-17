b = [0,0,1,1]
c = [0,0,0,1]
for i in range(4,10001):
    b.append(b[-2]+1)
    c.append(b[-4]+c[-3]+1)
for _ in range(int(input())):
    n = int(input())
    print(1+b[n]+c[n])
