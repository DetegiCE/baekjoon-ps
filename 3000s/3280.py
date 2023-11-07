n = int(input())
d = int(input())
p = []
c = []
s = []
for i in range(n):
    p.append(i)
    c.append(i)
    s.append(0)
for _ in range(d):
    a = input()
    th = 0
    if a == 'second': th = 1
    if a == 'third': th = 2
    
    for i in range(n):
        if i % 3 != th:
            c[p[i]] = 0
            
    for i in range(n):
        s[i] = p[i]
    
    t = 0
    for i in range(3):
        for j in range(n//3):
            p[t] = s[i+j*3]
            t += 1
    
for i in range(n):
    if c[i] > 0:
        print(i+1, end=' ')
