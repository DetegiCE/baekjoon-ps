n=int(input())
a=input()
for i in range(1,n+1):
    if a.startswith(str(i)):
        a = a[len(str(i)):]
    else:
        print(i)
        break