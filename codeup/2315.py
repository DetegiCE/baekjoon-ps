n = int(input())
m = int(input())
a = set()
for i in range(1, n+1):
    if(m % i == 0):
        a.add(i)
    if(i % m == 0):
        a.add(i)
print(len(a))