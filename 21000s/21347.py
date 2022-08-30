a=list(input())
b=list(input())
for i in a:
    if i in b:
        b.remove(i)
b=set(b)
for j in b:
    print(j, end='')