a=input().split(',')
c=0
for i in a:
    try:
        i=int(i)
        c+=1
    except:
        continue
print(c)