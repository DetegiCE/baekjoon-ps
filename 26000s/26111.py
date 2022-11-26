a=input()
b=-1
c=0
for i in range(len(a)):
    if a[i] == '(':
        b += 1
    else:
        if a[i-1] == '(':
            c += b
        b -= 1
print(c)