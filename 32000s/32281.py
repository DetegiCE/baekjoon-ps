n = int(input())
a = input()
b = []
for i in range(len(a)):
    if a[i] == '1':
        if i == 0: b.append(1)
        elif a[i-1] == '0': b.append(1)
        else: b[-1] += 1
c = 0
for i in b:
    c += i*(i+1)//2
print(c)